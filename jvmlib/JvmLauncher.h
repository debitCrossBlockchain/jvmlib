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
	void destroy_vm();
	jclass find_class(const std::string& class_name);
	void call_method(const jclass& j_class, const std::string& method_name, const std::string& args);
	jobject call_method_init(const jclass& j_class);
    private:
		JNIEnv* m_jvm_env;
		JavaVM* m_jvm;
		long m_status;
		HINSTANCE           m_dll_instance = nullptr;
		std::string         m_java_home;
		std::string         m_product_lib_dir;
		std::string         m_jvm_dll_location;
};

