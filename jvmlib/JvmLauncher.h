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
	void create_vm(const std::string& jar_path);
    private:
		JNIEnv* m_jvm_env;
		JavaVM* m_jvm;
		HINSTANCE           m_dll_instance = nullptr;
		std::string         m_java_home;
		std::string         m_product_lib_dir;
		std::string         m_jvm_dll_location;
};

