/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   i9corp_license.h
 * Author: sobrito
 *
 * Created on 16 de Outubro de 2018, 15:22
 */

#ifndef I9CORPLICENSE_H
#define I9CORPLICENSE_H

#include <i9corp/uid/i9corp_export.h>
#include <i9corp/uid/i9corp_license_base.h>

class DLL_EXPORT I9CorpLicense {
public:
    I9CorpLicense(const char *filename);
    I9CorpLicense();
    virtual ~I9CorpLicense();

    void setProperty(const char *name, long length);
    void setDictionary(const char *dictionary);
    void setDivisor(long length);

    void setPropertyValue(const char *name, long value);
    long getPropertyValue(const char *name);

    bool static check(const char *filename, const char *serial, const long salt);
    bool validate(long salt);

    const char *getSerial();
    void import(const char *serial, const long salt);
    void rebuild(long salt);
    void setHash(const char *hash);

    static bool checkTagMachine(const char *tag);
    static char * getTagMachine();
private:
    i9corp_license_base *lic;
};



#endif /* I9CORPLICENSE_H */

