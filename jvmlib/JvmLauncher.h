#pragma once
#ifdef _WIN32
#include "windows/jni.h"
#include "windows/jni_md.h"
#else
#include "linux/jni.h"
#include "linux/jni_md.h"
#endif
#include <Shlwapi.h>  
#pragma comment(lib,"Shlwapi.lib")
#include <string>
#include <vector>
#include <map>
#define CLEAR(x) memset(&x, 0, sizeof(x))
using namespace std;
class JvmLauncher
{
public:
	JvmLauncher();
	~JvmLauncher();
    private:
		JNIEnv* m_jvm_env;
		std::string m_java_home;
		HINSTANCE           m_hDllInstance = nullptr;

		std::string         m_JavaHome;
		std::string         m_ProductLibDir;
		std::string         m_JvmDllLocation;
};

