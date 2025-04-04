// decen/1exec/1call.cpp
#include "../utils-1exec.h"
#include <Python.h>



void __decen1exec_callPython(const char* scriptName, const char* functionName) {
    // Khởi tạo Python interpreter
    Py_Initialize();

    // Thêm đường dẫn thư mục plugins/python vào sys.path để tìm module Python
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\"plugins/python\")");

    // Tải module runtime từ Python
    PyObject* pName = PyUnicode_DecodeFSDefault(scriptName);
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        // Lấy hàm taskRun từ module runtime
        PyObject* pFunc = PyObject_GetAttrString(pModule, functionName);

        if (pFunc && PyCallable_Check(pFunc)) {
            // Gọi hàm taskRun từ Python
            PyObject* pValue = PyObject_CallObject(pFunc, nullptr);

            if (pValue != nullptr) {
                Py_DECREF(pValue);
            } else {
                PyErr_Print();
                std::cerr << "Gọi hàm " << functionName << " thất bại" << std::endl;
            }
            Py_DECREF(pFunc);
        } else {
            if (PyErr_Occurred()) PyErr_Print();
            std::cerr << "Không tìm thấy hàm '" << functionName << "'" << std::endl;
        }
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        std::cerr << "Không thể tải module '" << scriptName << "'" << std::endl;
    }

    // Giải phóng Python interpreter
    Py_Finalize();
}