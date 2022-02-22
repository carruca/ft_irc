SERVER		=	ircserv
CLIENT		=	irclient
SRCSPATH	=	src/
OBJSPATH	=	obj/
SERVEROBJS	=	$(patsubst $(SRCSPATH)%, $(OBJSPATH)%, $(SRCS:.cpp=.o))
SERVERDEPS	=	$(OBJS:.o=.d)
CLIENTOBJS	=	$(patsubst $(SRCSPATH)%, $(OBJSPATH)%, $(CSRCS:.cpp=.o))
CLIENTDEPS	=	$(CLIENTOBJS:.o=.d)
CXXFLAGS	=	-Wall -Wextra -Werror -MD -I$(INCLUDEPATH) $(COMMONFLAGS) -std=c++98
COMMONFLAGS	=	
LDFLAGS		=	$(LDLIBS) $(COMMONFLAGS)
LDLIBS		=	
INCLUDEPATH	=	./include/
FSANITIZE	=	-g3 -fsanitize=address
CXX			=	clang++
RM			=	rm -Rf

-include	sources.mk

all:	$(SERVER) $(CLIENT)
#all:	$(SERVER)

server: $(SERVER)
client:	$(CLIENT)

-include	$(SERVERDEPS) $(CLIENTDEPS)

$(OBJSPATH)%.o:	$(SRCSPATH)%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(SERVER):	$(SERVEROBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(CLIENT):	$(CLIENTOBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: += clean
clean:	clean_server clean_client

.PHONY: += clean_server
clean_server:
	$(RM) $(SERVEROBJS) $(SERVERDEPS)

.PHONY: += clean_client
clean_client:
	$(RM) $(CLIENTOBJS) $(CLIENTDEPS)

.PHONY: += fclean_server
fclean_server: clean_server
	$(RM) $(SERVERNAME) tags

.PHONY: += fclean_client
fclean_client: clean_client
	$(RM) $(CLIENTNAME) tags

.PHONY: += fclean
fclean:		fclean_server fclean_client

pre:
	$(CXX) -E -I $(INCLUDEPATH) $(filter-out $@,$(MAKECMDGOALS))

print:
	echo $(SRCS)
	echo $(OBJS)

.PHONY: += re
re:			fclean all

.PHONY: += debug
debug:		COMMONFLAGS = $(FSANITIZE)
debug:		$(SERVER) tag

.PHONY: += release
release:	COMMONFLAGS = -O3
release:	$(SERVER)
	strip $(SERVER)

.PHONY: += tag
tag:
	ctags	$(SRCS)

.PHONY: += run
run:		all
	./$(SERVER)

.PHONY: += cli
cli:
	make -C client run non NoSoyNadie 127.0.0.1 6667
	reset

.PHONY: += hispano
hispano:
	make -C client run non NoSoyNadie 195.234.61.209 6667

.PHONY: += dalnet
dalnet:
	make -C client run non NoSoyNadie 143.244.34.1 6667

.SILENT:	clean fclean tag release print
