#ifndef __FingerPrintModule_H__
#define __FingerPrintModule_H__
/**
 * @File Name: FingerPrintModule.h
 * @Brief : 用一个调用指纹解锁算法的应用实例，实现模板方法
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2021-12-27
 *
 */

#include <stdio.h>
#include <iostream>

using namespace std;
//基类
class FingerPrintModule
{

public:
    FingerPrintModule() {}
    virtual ~FingerPrintModule() {}
    void getImage()
    {
        printf("采集指纹图像\n");
    }
    void output()
    {
        std::cout << "指纹图像处理完成" << std::endl;
    }
    //留给子类实现
    virtual bool isSafeMode() = 0;
    virtual void processImage() = 0;
    virtual void encrypt() = 0;
    virtual void decrypt() = 0;

    //模板方法：算法框架
    void algorithm()
    {
        // 1.采图
        getImage();

        // 2.安全模式下加解密
        if (isSafeMode())
        {
            // 2.1加密
            encrypt();
            // 2.2解密
            decrypt();
        }
        // 3.处理Image
        processImage();
        // 4.处理结果
        output();
    }
};

//派生类
class FingerPrintModuleA : public FingerPrintModule
{
public:
    FingerPrintModuleA() {}
    void processImage()
    {
        cout << "使用第一代算法 处理指纹图像" << endl;
    }
    bool isSafeMode()
    {
        cout << "安全模式" << endl;
        return true;
    }
    void encrypt()
    {
        cout << "使用RSA密钥加密" << endl;
    }
    void decrypt()
    {
        cout << "使用RSA密钥解密" << endl;
    }
};

class FingerPrintModuleB : public FingerPrintModule
{
public:
    FingerPrintModuleB() {}
    void processImage()
    {
        cout << "使用第二代算法 处理指纹图像" << endl;
    }
    bool isSafeMode()
    {
        cout << "非安全模式" << endl;
        return true;
    }
    void encrypt()
    {
    }
    void decrypt() {}
};
class FingerPrintModuleC : public FingerPrintModule
{
public:
    FingerPrintModuleC() {}
    void processImage()
    {
        cout << "使用第三代算法 处理指纹图像" << endl;
    }
    bool isSafeMode()
    {
        cout << "安全模式" << endl;
        return true;
    }
    void encrypt()
    {
        cout << "使用DH密钥加密" << endl;
    }
    void decrypt()
    {
        cout << "使用DH密钥加密" << endl;
    }
};
#endif