#pragma once

//���ļ�����Ϊ��һ��ͨ�õĽ����ƽ̨�ṩ��ͷ��Ϣת��Ϊһ���������ڲ��ý�Ϊ�׶�������д�ɵĽӿ�
//���������������ַ��ӵ�ͷ�ļ�Ԥ����ָ�ֻ��Ҫ����
//��ͷ�ļ��еĺ궨��Ϊ�������к궨�壬����ͬʱ���ڴ����Ⱥ�ϸ���ȵĺ�ͬʱ������

//
//BASIC
//Ĭ�ϲ��ֹ�����
//�������ݿ��ں������Զ�����
//

#ifdef _DEBUG
#define DEBUG
#endif

#ifdef _RELEASE
#define RELEASE
#endif

//#define DEBUG
//#define DEBUG_ARGUMENT
//#define RELEASE
//#define PUBLISH

//
//MODE
//Ĭ���ֹ�����
//

#define MODE_MILD      //��һ�㣬�ȹ�
//#define MODE_VIOLENT //�������壬�����ø�����ܵ��˹�����
//#define MODE_ARGUMENT //������
//#define MODE_NOLOGO //����LOGO

//
//SYSTEM & ARCHITECTURE
//Ĭ�ϲ��ֹ�����
//���ü��ͷ�ļ��ж���ķ�ʽ���Զ�������ϵͳ����
//

#ifdef _WIN32
#ifndef SYSTEM_WINDOWS
#define SYSTEM_WINDOWS
#endif // !SYSTEM_WINDOWS
#ifndef ARCHITECTURE_x86
#define ARCHITECTURE_x86
#endif // !ARCHITECTURE_x86

#endif // _WIN32_WINNT

#ifdef _WIN32_WINNT
#ifndef SYSTEM_WINDOWS
#define SYSTEM_WINDOWS
#endif // !SYSTEM_WINDOWS
#endif // _WIN32_WINNT

#ifdef linux
    #define SYSTEM_LINUX
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	struct utsname buf;

	if (uname(&buf))
	{
		perror("uname");
		exit(1);
	}

	printf("sysname:%s\n", buf.sysname);
	printf("nodename:%s\n", buf.nodename);
	printf("release:%s\n", buf.release);
	printf("version:%s\n", buf.version);
	printf("machine:%s\n", buf.machine);

	return 0;
}
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
//#define SYSTEM_MCU //��Ƭ��(�޲���ϵͳ)

//#define ARCHITECTURE_x86 //x86 16λ/32λ CISC����ָ�
//#define ARCHITECTURE_8086 //x86 16λ CISC����ָ�
//#define ARCHITECTURE_i386 //x86 32λ CISC����ָ�
//#define ARCHITECTURE_i486 //x86 32λ CISC����ָ�
//#define ARCHITECTURE_i586 //x86 32λ CISC����ָ�
//#define ARCHITECTURE_i686 //x86 32λ CISC����ָ�
//#define ARCHITECTURE_ia64 //Itanium 64λ CISC����ָ�
//#define ARCHITECTURE_x64 //x64 64λ CISC����ָ�
//#define ARCHITECTURE_x86_64 //x64 64λ CISC����ָ�
//#define ARCHITECTURE_amd64 //x64 64λ CISC����ָ�
//#define ARCHITECTURE_arm //arm Any RISC����ָ�
//#define ARCHITECTURE_MIPS //mips Any RISC����ָ�
//#define ARCHITECTURE_RISC_V //RISCV Any RISC����ָ�


//
//COMPLIER
//Ĭ�ϲ��ֹ�����
//ͨ�����ֱ�ǽ��м��
//

#ifdef _MSC_VER
	#ifndef COMPLIER_MSVC
	    #define COMPLIER_MSVC
	#endif // !COMPLIER_MSVC
	#ifndef SYSTEM_WINDOWS
	    #define SYSTEM_WINDOWS
	#endif // !SYSTEM_WINDOWS
	#if _MSC_VER>=1800 //MSVC++ 12.0 (Visual Studio 2013 version 12.0) and after
		#ifndef APPLICATION_SDL_AVALIABLE
		    #define APPLICATION_SDL_AVALIABLE
		#endif
	#else if _MSC_VER<=1200 //MSVC++ 6.0 (Visual Studio 6.0 version 6.0) and before
	    #define APPLICATION_VC6_0_FEATURE
	#endif
#endif // _MSC_VER

//#define COMPLIER_MSVC
//#define COMPLIER_GCC
//#define COMPLIER_ICC
//#define COMPLIER_MINGW


//
//LANGUAGE
//Ĭ���ֹ�����
//�ڿ�����θ���ϵͳ�����Լ�ͷ�ļ���������ԣ����ܱȽ����ѣ������˹�ָ��
//

//�Զ����в�ʶ���ж�
#ifdef SYSTEM_WINDOWS
#include <stdio.h>
#include <Windows.h>
#include <Winnls.h>

#pragma comment(lib,"Kernel32.lib")

LANGID lid = GetSystemDefaultLangID(); // ��ȡϵͳĬ��ID
switch (lid)
{
	case 0x0804:
#define zh_CN
#define LANGUAGE_zh_CN
		break;
	case 0x0409:
#define en_US
#define LANGUAGE_en_US
		break;
}
return 0;
#else
#define zh_CN
#define LANGUAGE_zh_CN
#endif // SYSTEM_WINDOWS


//#define en_US
//#define LANGUAGE_en_US
//#define ja_JP
//#define LANGUAGE_ja_JP
//#define LANGUAGE_OTHERS

//
//APPLICATION
//�����˳���Ӧ�öԿ�����������������Ϣ
//

#ifdef __openmp
#define
#endif // __openmp


//#define APPLICATION_OpenMP_AVAILABLE //����OMP
//#define APPLICATION_pThread_AVAILABLE //����pThread
//#define APPLICATION_MPI_AVAILABLE //����MPI
//#define APPLICATION_NUMA_AVAILABLE //����NUMA
//#define APPLICATION_SDL_AVALIABLE  //��C++11��sdl��飬Ŀǰ��֧��MSVC

#ifdef SYSTEM_WINDOWS && COMPLIER_MSVC
#define APPLICATION_EASYX
#endif // APPLICATION_EASYX


//
//REFERENCE
//

//https://docs.microsoft.com/en-us/cpp/porting/modifying-winver-and-win32-winnt?view=vs-2019
//https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B

https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getsystemdefaultlangid
https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getuserdefaultlangid
https://docs.microsoft.com/en-us/windows/win32/msi/systemlanguageid