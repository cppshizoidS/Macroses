/**
 * @file msg.hpp
 * @brief Defines the MsgType class and macros for creating message types.
 */
#ifndef MSG_HPP
#define MSG_HPP

#include <stdint.h>
/**
 * @brief Template class for defining message types.
 * @tparam T The type of data associated with the message.
 * @tparam MSG_TYPE The unique identifier for the message type.
 */
template <class T, int MSG_TYPE>
class __attribute__((packed)) MsgType {
public:
    MsgType(const T & data):type(MSG_TYPE),data(data){}
    MsgType():type(MSG_TYPE){}
    int type;
    T data;
    char * getData(){return (char *)this;}
    static unsigned int getSize(){return sizeof(MsgType<T,MSG_TYPE>);}
    static inline unsigned char getCode(){return MSG_TYPE;}
};

/**
 * @brief Macro for defining a message type.
 * @param msg_name The name of the message type.
 * @param number The unique identifier for the message type.
 * @param data Data structure associated with the message type.
 */
#define MSG_TYPE(msg_name,number,data) \
struct __attribute__((packed)) msg_name ## _T data ; \
typedef MsgType< msg_name ## _T, number> msg_name;

/**
 * @brief Macro for starting the definition of a message type.
 * @param name The name of the message type.
 */
#define MSG_START(name)\
    class __attribute__((packed)) name\
    {\
    public:
/**
 * @brief Macro for ending the definition of a message type.
 */
#define MSG_END\
    };
/**
 * @brief Macro for defining the header of a message type.
 * @param code The code associated with the message type.
 */
#define MSG_TYPE_HEADER(code) \
    type(code)
/**
 * @brief Macro for defining the body of a message type.
 * @param name The name of the message type.
 * @param code The code associated with the message type.
 */
#define MSG_TYPE_BODY(name,code) \
    char * getData(){return (char *)this;}\
    static unsigned int getSize(){return sizeof(name);}\
    static inline unsigned char getCode(){return code;}\
    uint8_t type;
/**
 * @brief Macro for defining a message type with 0 arguments.
 * @param name The name of the message type.
 * @param code The code associated with the message type.
 */
#define MSG_TYPE_0(name, code) \
    MSG_START(name)\
        name():MSG_TYPE_HEADER(code){}\
        MSG_TYPE_BODY(name,code)\
    MSG_END
/**
 * @brief Macro for defining a message type with 1 argument.
 * @param name The name of the message type.
 * @param code The code associated with the message type.
 * @param type1 Type of the first argument.
 * @param arg1 Name of the first argument.
 * @param def1 Default value for the first argument.
 */
#define MSG_TYPE_1(name, code, type1, arg1, def1) \
    MSG_START(name)\
        name(type1 arg1 = def1):MSG_TYPE_HEADER(code),arg1(arg1){}\
        MSG_TYPE_BODY(name,code)\
        type1 arg1;\
    MSG_END
/**
 * @brief Macro for defining a message type with 2 arguments.
 * @param name The name of the message type.
 * @param code The code associated with the message type.
 * @param type1 Type of the first argument.
 * @param arg1 Name of the first argument.
 * @param def1 Default value for the first argument.
 * @param type2 Type of the second argument.
 * @param arg2 Name of the second argument.
 * @param def2 Default value for the second argument.
 */
#define MSG_TYPE_2(name, code, type1, arg1, def1, type2, arg2, def2) \
    MSG_START(name)\
        name(type1 arg1 = def1, type2 arg2 = def2):MSG_TYPE_HEADER(code),arg1(arg1),arg2(arg2){}\
        MSG_TYPE_BODY(name,code)\
        type1 arg1;\
        type2 arg2;\
    MSG_END


#endif // MSG_HPP