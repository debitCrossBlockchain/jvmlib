#include "JvmLauncher.h"
JvmLauncher::JvmLauncher() {

}

void JvmLauncher::create_vm(const std::string& jar_path){
    JavaVMInitArgs vm_args;
    JavaVMOption options[3];

   /* options[0].optionString = "-Djava.compiler=NONE";
    options[1].optionString = jar_path.c_str();
    options[2].optionString = "-verbose:jni";*/

    vm_args.options = options;
    vm_args.nOptions = 3;
    vm_args.ignoreUnrecognized = 0;
    vm_args.ignoreUnrecognized = JNI_TRUE;
    vm_args.version = JNI_VERSION_1_8;

    int status = JNI_CreateJavaVM(&m_jvm, (void**)&m_jvm_env, &vm_args);
    if (status < 0 || !m_jvm_env) {
        printf("Error: %d\n", status);
        return;
    }
}

JvmLauncher::~JvmLauncher() {

}