
#include <iostream>
#include <string>
using namespace std;

struct Exception {
  string _msg;
  Exception() : _msg("I") {}
  Exception(const Exception& fellow) : _msg(fellow._msg + "C") { }
  Exception(Exception &&fellow) : _msg(forward<string>(fellow._msg)){ _msg += "M"; }
  template<typename T> Exception&& operator+(const T& item) {
   _msg += item;
   return std::move(*this);

  }
};

struct IOException : public Exception {
};

struct FileException : public IOException {
};

int main() {

  try {

    throw FileException() + "P";
  }
  catch (FileException ex) {
    cout << "F" << ex._msg;
  }
  catch (IOException ex) {
    cout << "I" << ex._msg;
  }
  catch (Exception ex) {
    cout << "E" << ex._msg;
  }

  return 0;

}

