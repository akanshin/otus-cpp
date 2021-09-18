#ifndef OTUS_CPP_OTUS_EXPORTS_H
#define OTUS_CPP_OTUS_EXPORTS_H

#ifdef OTUS_EXPORT
    #ifdef _WIN32
        #define OTUS_API __declspec(dllexport)
    #else
        #define OTUS_API __attribute__((visibility("default")))
    #endif
#else
    #define OTUS_API
#endif

#endif //OTUS_CPP_OTUS_EXPORTS_H
