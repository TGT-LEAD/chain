##===================================================================##
## File Name: makefile
##
## Create Author: Tom Hui
##
## Create Date: Web Jan 24 2207 2018
##
## Description:
##		
##===================================================================##

include ../inc.mk

TARGET :=
TARGET_ME = ${BIN_PATH}/lktWallet
ifneq "$(OS_NAME)" "Linux"
TARGET += ${TARGET_ME}.exe
else 
TARGET += ${TARGET_ME}
endif

SRC = $(wildcard *.cpp)
COMM_SRC = $(wildcard ../safeMiddle/common/*.cpp)
SRC += ${COMM_SRC}

OBJS = ${patsubst %.cpp, %.o, ${SRC}}


CXX_INCLUDE += -I../../huibase/src
CXX_INCLUDE += -I../../huibase/crypto
CXX_INCLUDE += -I../../huibase/http
CXX_INCLUDE += -I../core
CXX_INCLUDE += -I../deps/jsoncpp/include
CXX_INCLUDE += -I../deps/libevent/include
CXX_INCLUDE += -I../deps/jsoncpp/include
CXX_INCLUDE += -I../deps/curl/include
CXX_INCLUDE += -I../deps/openssl/include
LINK_CXX_LIBS += -L../../huibase/lib
LINK_CXX_LIBS += -lhuibase -lcore -lhuicrypto -lhuihttp
LINK_CXX_LIBS += ../deps/jsoncpp/build/src/lib_json/libjsoncpp.a
LINK_CXX_LIBS += -L../deps/glog/.libs/ -lglog -lpthread
LINK_CXX_LIBS += -L../deps/db48/build_unix -lpthread
LINK_CXX_LIBS += ../deps/leveldb/libleveldb.a -lpthread
LINK_CXX_LIBS += ../deps/openssl/libssl.a ../deps/openssl/libcrypto.a -lpthread
LINK_CXX_LIBS += ../deps/libevent/.libs/libevent.a
LINK_CXX_LIBS += ../deps/jsoncpp/build/src/lib_json/libjsoncpp.a
LINK_CXX_LIBS += ../deps/curl/lib/.libs/libcurl.a
LINK_CXX_LIBS += ../deps/openssl/libssl.a ../deps/openssl/libcrypto.a -lz
LINK_CXX_LIBS += ../deps/curl/lib/.libs/libcurl.a -lz

CXX_CFLAGS += -fstack-protector-all
LINK_CXX_CFLAGS += -fstack-protector-all 

ifeq "$(OS_NAME)" "Darwin"
LINK_CC_LIBS += -liconv
endif

LINK_CXX_LIBS += -ldl

TTYPE = EFILE

all: def

def: ${TARGET}

test_me:
	@echo ${OBJS}


include ../route.mk

