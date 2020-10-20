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

#ifdef __cplusplus
#define CPP
#else
#define C
#endif // __cplusplus


//#define C
//#define CPP
//#define DEBUG
//#define RELEASE
//#define PUBLISH

//
//MODE
//Ĭ���ֹ�����
//

#define MODE_MILD      //��һ�㣬�ȹ�
//#define MODE_VIOLENT //�������壬�����ø�����ܵ�ʵ���Լ���
//#define MODE_ARGUMENT //������
//#define MODE_NOLOGO //����LOGO

//
//SYSTEM & ARCHITECTURE
//Ĭ�ϲ��ֹ�����
//���ü��ͷ�ļ��ж���ķ�ʽ���Զ�������ϵͳ����
//

#ifndef WINVER
#define WINVER 0x0400			// Specifies that the minimum required platform is Windows 95 and Windows NT 4.0.
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500		// Specifies that the minimum required platform is Windows 2000.
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410	// Specifies that the minimum required platform is Windows 98.
#endif

#ifdef UNICODE
//UNICODE
#else
//ASCII
#endif

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

#ifdef ( linux or __linux__ or _linux_ or _linux or __linux )
#ifndef SYSTEM_LINUX
#define SYSTEM_LINUX
#endif // !SYSTEM_LINUX
	
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
#error can not use
	}

	printf("sysname:%s\n", buf.sysname);
	printf("nodename:%s\n", buf.nodename);
	printf("release:%s\n", buf.release);
	printf("version:%s\n", buf.version);
	printf("machine:%s\n", buf.machine);

	return 0;
}
#endif // linux

#ifdef _unix or _unix_ or _UNIX or _UNIX_
#ifndef SYSTEM_UNIX
#define SYSTEM_UNIX
#endif // !SYSTEM_UNIX
#endif // UNIX


#ifdef __sun
#ifndef SYSTEM_SOLARIS
#define SYSTEM_SOLARIS
#endif // !SYSTEM_SOLARIS
#endif // __sun

#ifdef __APPLE__
#ifndef SYSTEM_IOS
#define SYSTEM_IOS
#endif // !SYSTEM_IOS
#endif // __APPLE__

#ifdef __ANDROID__
#ifndef SYSTEM_ANDROID
#define SYSTEM_ANDROID
#endif // !SYSTEM_ANDROID
#endif // __ANDROID__



//#define SYSTEM_WINDOWS
//#define SYSTEM_LINUX
//#define SYSTEM_UNIX
//#define SYSTEM_MACOS
//#define SYSTEM_IPADOS
//#define SYSTEM_IOS
//#define SYSTEM_ANDROID
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
//#define ARCHITECTURE_STM32 //��Ƭ��


//
//COMPLIER
//Ĭ�ϲ��ֹ�����
//ͨ�����ֱ�ǽ��м��
//

#ifdef _MSC_VER or _MSVC_
	#ifndef COMPLIER_MSVC
	    #define COMPLIER_MSVC
	#endif // !COMPLIER_MSVC
	#ifndef SYSTEM_WINDOWS
	    #define SYSTEM_WINDOWS
	#endif // !SYSTEM_WINDOWS
	#if _MSC_VER>=1800 //MSVC++ 12.0 (Visual Studio 2013 version 12.0) and after
		#ifndef STANDARD_SDL_AVALIABLE
		    #define STANDARD_SDL_AVALIABLE
		#endif
		#ifndef STANDARD_STL_AVALIABLE
			#define STANDARD_STL_AVALIABLE
		#endif
	#else if _MSC_VER<=1200 //MSVC++ 6.0 (Visual Studio 6.0 version 6.0) and before
		#ifndef STANDARD_SDL_UNAVALIABLE
			#define STANDARD_SDL_UNAVALIABLE
		#endif
		#ifndef STANDARD_STL_UNAVALIABLE
			#define STANDARD_STL_UNAVALIABLE
		#endif
	    #define APPLICATION_VC6_0_FEATURE
	#endif
#endif // _MSC_VER

#ifdef __GNUC or __GNUC__

#endif // __GNUC


#ifdef __ICC
	#ifndef __ICC
		#define COMPLIER_ICC
	#endif // !__ICC
	#ifndef STANDARD_STL_UNAVALIABLE
		#define STANDARD_STL_UNAVALIABLE
	#endif // !STANDARD_STL_UNAVALIABLE
#endif // __ICC

#ifdef __BORLANDC__

#endif // __BORLANDC__


//#define COMPLIER_MSVC
//#define COMPLIER_GCC
//#define COMPLIER_ICC
//#define COMPLIER_MINGW
//#define COMPLIER_SUNCC
//#define COMPLIER_BORLANDC


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
#pragma  message("zh_CN")
		break;
	case 0x0409:
#define en_US
#define LANGUAGE_en_US
#pragma  message("en_US")
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
#define APPLICATION_OpenMP_AVAILABLE
#endif // __openmp

//APPLICATION - MULTI PROCESS
//#define APPLICATION_OpenMP_AVAILABLE //����OMP
//#define APPLICATION_pThread_AVAILABLE //����pThread
//#define APPLICATION_MPI_AVAILABLE //����MPI
//#define APPLICATION_NUMA_AVAILABLE //����NUMA

//APPLICATION - GUI
#ifdef SYSTEM_WINDOWS && COMPLIER_MSVC
#define APPLICATION_EASYX
#endif // APPLICATION_EASYX

//#define APPLICATION_MFC
//#define APPLICATION_GTK
//#define APPLICATION_QT
//#define APPLICATION_OpenGL
//��ע��������õ�Ϊmacos��ʱ���Զ��ر�opengl���ݲ���������ǿ�����ÿ����ͼ����opengl��ʱ����һ���Ƿ���macos
//#define APPLICATION_VULKAN  //macos
//#define APPLICATION_METAL //macos
//#define APPLICATION_EASYX

//APPLICATION - OTHERS
//#define APPLICATION_VC6_0_FEATURE

//
//STANDARD
//

#if __cplusplus >=201103L
#ifndef STANDARD_SDL_AVALIABLE
#define STANDARD_SDL_AVALIABLE
#endif
#endif

//#define STANDARD_SDL_AVALIABLE  //��C++11��sdl��飬Ŀǰ��֧��MSVC
//#define STANDARD_SDL_UNAVALIABLE  //��֧��SDL
//#define STANDARD_STL_AVALIABLE  //����C++����������C�������Ͼɱ������Ϳ�ѧ��������֧��STL.(MSVC7/IC8 and earlier)
//#define STANDARD_STL_UNAVALIABLE  //��֧��STL
//#define STANDARD_EXCEPTIONS_AVALIABLE  //֧���쳣
//#define STANDARD_EXCEPTIONS_UNAVALIABLE  //��֧���쳣
//#define STANDARD_UNICODE_AVALIABLE

//����__cplusplus
//c++ 98�У���199711L���ܶ�汾�������ֵ��
//c++ 11�У���201103L

//
//REFERENCE
//

https://docs.microsoft.com/en-us/cpp/porting/modifying-winver-and-win32-winnt?view=vs-2019
https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B
https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getsystemdefaultlangid
https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getuserdefaultlangid
https://docs.microsoft.com/en-us/windows/win32/msi/
https://sourceforge.net/p/predef/wiki/Architectures/