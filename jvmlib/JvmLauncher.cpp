#include "JvmLauncher.h"
JvmLauncher::JvmLauncher() {
    char* p_value = getenv("JAVA_HOME");
    if (p_value != NULL) {
        m_java_home = p_value;
    }
}

void JvmLauncher::create_vm(const std::string& jar_path){
    JavaVMInitArgs vm_args;
    JavaVMOption options[3];
    options[0].optionString = const_cast<char*>("-Djava.compiler=NONE");
    options[1].optionString = const_cast<char*>(jar_path.c_str());
    options[2].optionString = const_cast<char*>("-verbose:jni");

    vm_args.options = options;
    vm_args.nOptions = 3;
    vm_args.ignoreUnrecognized = 0;
    vm_args.ignoreUnrecognized = JNI_TRUE;
    vm_args.version = JNI_VERSION_1_8;

    m_status = JNI_CreateJavaVM(&m_jvm, (void**)&m_jvm_env, &vm_args);
    if (m_status < 0 || !m_jvm_env) {
        printf("Error: %d\n", m_status);
        return;
    }
}

jclass JvmLauncher::find_class(const std::string& class_name){
    if (m_status != JNI_ERR && m_jvm_env != NULL) {
        return m_jvm_env->FindClass(class_name.c_str());
    }
}

void JvmLauncher::call_method(const jclass& j_class, const std::string& method_name, const std::string& args) {
    if (j_class != 0&& m_jvm_env!=NULL) {
        // µ÷ÓÃmainº¯Êý
        jmethodID mid = m_jvm_env->GetStaticMethodID(j_class, method_name.c_str(), args.c_str());
        if (mid != 0) {
            m_jvm_env->CallStaticIntMethod(j_class, mid);
        }
    }
}

jobject JvmLauncher::call_method_init(const jclass& j_class) {
    if (j_class != 0 && m_jvm_env != NULL) {
        jmethodID mid = m_jvm_env->GetMethodID(j_class, "<init>", "()V");
        if (mid != 0) {
            return m_jvm_env->NewObject(j_class, mid);
        }
    }
}


void JvmLauncher::destroy_vm() {
    if (m_status != JNI_ERR&&m_jvm != NULL) {
        m_jvm->DestroyJavaVM();
    }
}

JvmLauncher::~JvmLauncher() {

}