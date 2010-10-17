#ifndef _OFFSCREENCONTEXT_H
#define _OFFSCREENCONTEXT_H

class COffscreenGLContext;
class COffscreenContext
{
public:
	//! Note: the functions are sorted in the way they should be called
	COffscreenContext();
	~COffscreenContext();
	void WorkerThreadPost();
	void WorkerThreadFree(); //! must run in the same thread as the offscreen GL context!
private:
	COffscreenGLContext* ogc;
};
#endif
