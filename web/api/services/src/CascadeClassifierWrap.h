#include "OpenCV.h"

class CascadeClassifierWrap: public node::ObjectWrap {
  public: 
 	cv::CascadeClassifier cc;

	static Persistent<FunctionTemplate> constructor;
	static void Init(Handle<Object> target);
	static Handle<Value> New(const Arguments &args);

	CascadeClassifierWrap(v8::Value* fileName);   

    //static Handle<Value> LoadHaarClassifierCascade(const v8::Arguments&);

	static Handle<Value> DetectMultiScale(const v8::Arguments&);
	// static void EIO_DetectMultiScale(uv_work_t *req);
	// static int EIO_AfterDetectMultiScale(uv_work_t *req);
	static void AsyncDetectMultiScale(uv_work_t *req);
	static void AfterAsyncDetectMultiScale(uv_work_t *req);

};