#ifndef SSF_COMMON_FILESYSTEM_PATH_H_
#define SSF_COMMON_FILESYSTEM_PATH_H_

#include <string>

#include <boost/filesystem.hpp>

namespace ssf {

class Path {
 public:
  Path();
  Path(const Path& path);
  Path(const boost::filesystem::path& path);
  Path(const std::string& path);
  Path(const char* path);

  ~Path();

  Path& operator=(const Path& other);
  Path& operator=(const std::string& other);
  Path& operator=(const char* other);

  Path& operator/=(const Path& other);
  Path& operator/=(const std::string& other);
  Path& operator/=(const char* other);

  Path& operator+=(const Path& other);
  Path& operator+=(const std::string& other);
  Path& operator+=(const char* other);

  bool operator==(const Path& path) const;

  friend Path operator/(Path lhs, const Path& rhs) {
    lhs /= rhs;
    return lhs;
  }

  Path GetParent() const;
  Path GetFilename() const;
  Path GetExtension() const;
  bool IsEmpty() const;
  bool IsRelative() const;
  bool IsAbsolute() const;
  bool HasExtension() const;

  Path MakeRelative(const Path& base, boost::system::error_code& ec) const;

  std::string GetString() const;

 private:
  boost::filesystem::path path_;
};

}  // ssf

#endif  // SSF_COMMON_FILESYSTEM_PATH_H_
