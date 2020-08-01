#pragma once

//���ļ�����Ϊ��һ��ͨ�õĽ����ƽ̨�ṩ��ͷ��Ϣת��Ϊһ���������ڲ��ý�Ϊ�׶�������д�ɵĽӿ�
//���������������ַ��ӵ�ͷ�ļ�Ԥ����ָ�ֻ��Ҫ����

//
//BASIC
//Ĭ�ϲ��ֹ�����
//�������ݿ��ں������Զ�����
//

#ifdef _DEBUG
#define DEBUG
#endif

//#define DEBUG
//#define DEBUG_ARGUMENT
//#define RELEASE
//#define PUBLISH
//#define OpenMP_AVAILABLE //��OMP
//#define SDL_AVALIABLE  //��C++11��sdl��飬Ŀǰ��֧��MSVC

//
//MODE
//Ĭ���ֹ�����
//

#define MODE_MILD     //��һ�㣬�ȹ�
//#define MODE_VIOLENT//�������壬�����ø�����ܵ��˹�����
//#define MODE_ARGUMENT//����

//
//SYSTEM
//Ĭ�ϲ��ֹ�����
//���ü��ͷ�ļ��ж���ķ�ʽ���Զ�������ϵͳ����
//

#ifdef (_WIN32

#endif // _WIN32_WINNT

#ifdef linux
    #define SYSTEM_LINUX
#endif // linux

#ifdef __sun
    #define SYSTEM_SOLARIS
#endif // __sun

//#define SYSTEM_WINDOWS
//#define SYSTEM_LINUX
//#define SYSTEM_UNIX
//#define SYSTEM_MACOS
//#define SYSTEM_IPADOS
//#define SYSTEM_SOLARIS
//#define SYSTEM_OTHERS
//#define SYSTEM_MCU //��Ƭ��

//
//COMPLIER
//Ĭ�ϲ��ֹ�����
//ͨ�����ֱ�ǽ��м��
//

#ifdef _MSC_VER
#define SYSTEM_WINDOWS
#if _MSC_VER>=1800 //MSVC++ 12.0 (Visual Studio 2013 version 12.0) and after
#define SDL_AVALIABLE
#else if _MSC_VER<=1200 //MSVC++ 6.0 (Visual Studio 6.0 version 6.0) and before
#define VC6_0
#endif
#endif
#else
#endif // _MSC_VER

//#define 

//
//LANGUAGE
//Ĭ���ֹ�����
//�ڿ�����θ���ϵͳ�����Լ�ͷ�ļ���������ԣ����ܱȽ����ѣ������˹�ָ��
//

#define zh_CN
#define LANGUAGE_zh_CN
//#define en_US
//#define LANGUAGE_en_US
//#define ja_JP
//#define LANGUAGE_ja_JP
//#define LANGUAGE_OTHERS

//
//REFERENCE
//

//https://docs.microsoft.com/en-us/cpp/porting/modifying-winver-and-win32-winnt?view=vs-2019
//https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B