#include "OffscreenContext.h"
#include "OffscreenGLContext.h"
COffscreenContext::COffscreenContext()
{
	ogc = new COffscreenGLContext;
}
COffscreenContext::~COffscreenContext()
{
	delete ogc;	
}
void COffscreenContext::WorkerThreadPost()
{
	ogc->WorkerThreadPost();
}
void COffscreenContext::WorkerThreadFree()
{
	ogc->WorkerThreadFree();
} 
