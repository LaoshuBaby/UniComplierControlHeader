#pragma once

//本文件作用为起到一个通用的将多个平台提供的头信息转化为一个本程序内部用较为易懂的语言写成的接口
//开发者无需记忆各种繁杂的头文件预处理指令，只需要负责
//本头文件中的宏定义为非排他行宏定义，可能同时存在粗粒度和细粒度的宏同时被定义

//
//BASIC
//默认不手工开启
//部分内容可在后文中自动定义
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
//默认手工开启
//

#define MODE_MILD      //稳一点，先过
//#define MODE_VIOLENT //激进主义，将采用更多可能的实验性技术
//#define MODE_ARGUMENT //允许传参
//#define MODE_NOLOGO //不带LOGO

//
//SYSTEM & ARCHITECTURE
//默认不手工开启
//采用检测头文件中定义的方式来自动化定义系统控制
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
#ifdef __linux__
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
//#define SYSTEM_MCU //单片机(无操作系统)

//#define ARCHITECTURE_x86 //x86 16位/32位 CISC复杂指令集
//#define ARCHITECTURE_8086 //x86 16位 CISC复杂指令集
//#define ARCHITECTURE_i386 //x86 32位 CISC复杂指令集
//#define ARCHITECTURE_i486 //x86 32位 CISC复杂指令集
//#define ARCHITECTURE_i586 //x86 32位 CISC复杂指令集
//#define ARCHITECTURE_i686 //x86 32位 CISC复杂指令集
//#define ARCHITECTURE_ia64 //Itanium 64位 CISC复杂指令集
//#define ARCHITECTURE_x64 //x64 64位 CISC复杂指令集
//#define ARCHITECTURE_x86_64 //x64 64位 CISC复杂指令集
//#define ARCHITECTURE_amd64 //x64 64位 CISC复杂指令集
//#define ARCHITECTURE_arm //arm Any RISC精简指令集
//#define ARCHITECTURE_MIPS //mips Any RISC精简指令集
//#define ARCHITECTURE_RISC_V //RISCV Any RISC精简指令集
//#define ARCHITECTURE_STM32 //单片机


//
//COMPLIER
//默认不手工开启
//通过各种标记进行检测
//

#ifdef _MSC_VER
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

#ifdef __GNUC

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
//默认手工开启
//在考虑如何根据系统环境以及头文件来检测语言，可能比较困难，初步人工指定
//

//自动运行并识别判断
#ifdef SYSTEM_WINDOWS
#include <stdio.h>
#include <Windows.h>
#include <Winnls.h>

#pragma comment(lib,"Kernel32.lib")

LANGID lid = GetSystemDefaultLangID(); // 获取系统默认ID
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
//记载了常见应用对开发环境到底需求信息
//

#ifdef __openmp
#define
#endif // __openmp

//APPLICATION - MULTI PROCESS
//#define APPLICATION_OpenMP_AVAILABLE //允许OMP
//#define APPLICATION_pThread_AVAILABLE //允许pThread
//#define APPLICATION_MPI_AVAILABLE //允许MPI
//#define APPLICATION_NUMA_AVAILABLE //允许NUMA

//APPLICATION - GUI
#ifdef SYSTEM_WINDOWS && COMPLIER_MSVC
#define APPLICATION_EASYX
#endif // APPLICATION_EASYX

//#define APPLICATION_MFC
//#define APPLICATION_GTK
//#define APPLICATION_QT
//#define APPLICATION_OpenGL
//备注，如何设置当为macos的时候自动关闭opengl？暂不清楚，但是可以在每次试图开启opengl的时候检查一下是否是macos
//#define APPLICATION_VULKAN  //macos
//#define APPLICATION_METAL //macos
//#define APPLICATION_EASYX

//APPLICATION - OTHERS
//#define APPLICATION_VC6_0_FEATURE

//
//STANDARD
//

//#define STANDARD_SDL_AVALIABLE  //开C++11的sdl检查，目前仅支持MSVC
//#define STANDARD_SDL_UNAVALIABLE  //不支持SDL
//#define STANDARD_STL_AVALIABLE  //仅限C++，并不包括C。部分老旧编译器和科学编译器不支持STL.(MSVC7/IC8 and earlier)
//#define STANDARD_STL_UNAVALIABLE  //不支持STL
//#define STANDARD_EXCEPTIONS_AVALIABLE  //支持异常
//#define STANDARD_EXCEPTIONS_UNAVALIABLE  //不支持异常

//
//REFERENCE
//

//https://docs.microsoft.com/en-us/cpp/porting/modifying-winver-and-win32-winnt?view=vs-2019
//https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B

https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getsystemdefaultlangid
https://docs.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getuserdefaultlangid
https://docs.microsoft.com/en-us/windows/win32/msi/systemlanguageid