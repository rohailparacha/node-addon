#include <node.h>

namespace demo {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

// This is the implementation of the "add" method
// Input arguments are passed using the
// const FunctionCallbackInfo<Value>& args struct

 long double calculateFact(long double number){
  if ((number==0)||(number==1))
      return 1; 
   else
      return number*calculateFact(number-1);
}

void Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // Check the number of arguments passed.
  if (args.Length() < 1) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Should pass at least one argument",
                            NewStringType::kNormal).ToLocalChecked()));
    return;
  }

  // Check the argument types
  if (!args[0]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate,
                            "Wrong arguments",
                            NewStringType::kNormal).ToLocalChecked()));
    return;
  }

  // Perform the operation
  long double value =
      args[0].As<Number>()->Value();
  

  Local<Number> num = Number::New(isolate, calculateFact(value));

  // Set the return value (using the passed in
  // FunctionCallbackInfo<Value>&)
  args.GetReturnValue().Set(num);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "add", Add);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace demo