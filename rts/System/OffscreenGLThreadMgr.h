#ifndef _COFFSCREENGLTHREADMGR_H
#define _COFFSCREENGLTHREADMGR_H

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
class COffscreenGLThread;
COffscreenGLThread* CreateOffscreenGLThread(boost::function<void()> f);
void DestroyOffscreenGLThread(COffscreenGLThread*);

#endif
