//
// Created by sobrito on 02/09/2019.
//

#ifndef MAMUTE_CORE_LICENSE_H
#define MAMUTE_CORE_LICENSE_H

#ifdef _WIN32
#ifdef MAKE_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
#else
#define DLL_EXPORT
#endif

#include <string>
#include <map>
#include <exception>

namespace i9corp {

    class DLL_EXPORT License {
    public:
        class DLL_EXPORT LicenseException : std::exception {
        public:
            LicenseException(int code, const char *message, ...);

            virtual const char *what() const throw() {
                return this->mMessage;
            }

        private:
            char mMessage[4096];
        };

        class DLL_EXPORT Module {
        public:
            Module();

            ~Module();

        public:

            int getId() const;

            void setId(int id);

            int getLimit() const;

            void setLimit(int limit);

            int getCurrent() const;

            void setCurrent(int current);

            char *getName() const;

            void setName(const char *name);

            char *getVersion() const;

            void setVersion(const char *version);

            bool isEnabled() const;

            void setEnabled(bool enabled);

        private:
            int id;
            int limit;
            int current;
            char *name;
            char *version;
            bool enabled;
        };

        ~License();

        static bool isRegistered();

        static License *sign(const char *vendor);

        static bool revoke();

        static License *synchronize();


        static Module *getModule(const char *name);

        static char *info();


    public:
        int getId() const;

        int getProductId() const;

        int getTypeId() const;

        int getValidate() const;

        int getSynchronization() const;

        char *getKey() const;

        const std::map<std::string, Module *> &getModules() const;

    private:
        License();

        static License *instance;

        static License *getInstance();

        int id;
        int productId;
        int typeId;
        int validate;
        int synchronization;
        char *key;
    private:
        std::map<std::string, Module *> modules;
    };
}


#endif //MAMUTE_CORE_LICENSE_H
