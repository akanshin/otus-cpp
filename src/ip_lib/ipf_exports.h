#ifndef OTUS_CPP_IP_FILTER_EXPORTS_H
#define OTUS_CPP_IP_FILTER_EXPORTS_H

#ifdef OTUS_EXPORT
    #ifdef _WIN32
        #define IPF_API __declspec(dllexport)
    #else
        #define IPF_API __attribute__((visibility("default")))
    #endif
#else
    #define IPF_API
#endif

#endif //OTUS_CPP_IP_FILTER_EXPORTS_H
