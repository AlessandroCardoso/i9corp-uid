/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   i9corp_export.h
 * Author: sobrito
 *
 * Created on 16 de Outubro de 2018, 15:17
 */

#ifndef I9CORP_EXPORT_H
#define I9CORP_EXPORT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#ifdef I9CORP_UID_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
#else
#define DLL_EXPORT
#endif

#ifdef __cplusplus
}
#endif

#endif /* I9CORP_EXPORT_H */

