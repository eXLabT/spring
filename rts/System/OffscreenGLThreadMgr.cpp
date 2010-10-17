#include "OffscreenGLThreadMgr.h"
#include "OffscreenGLContext.h"
COffscreenGLThread* CreateOffscreenGLThread(boost::function<void()> f)
{
	return new COffscreenGLThread(f);
}
void DestroyOffscreenGLThread(COffscreenGLThread* t)
{
	delete t;
}
