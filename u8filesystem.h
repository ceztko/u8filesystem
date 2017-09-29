#pragma once

#include <filesystem>
#include <string>

namespace std
{
    namespace u8filesystem
    {
#ifdef WIN32
        using filesystem::copy_options;

        class path : public filesystem::path
        {
        public:
            path();
            path(const char* path);
            path(const std::string &string);
            path(const path &path);
            path(path &&path) noexcept;
            path(const filesystem::path &path);
            path(filesystem::path &&path) noexcept;

            inline std::string string() const
            {
                return filesystem::path::u8string();
            }

            inline path filename() const
            {
                return filesystem::path::filename();
            }

            inline path extension() const
            {
                return filesystem::path::extension();
            }

            inline path stem() const
            {
                return filesystem::path::stem();
            }

            inline path root_name() const
            {
                return filesystem::path::root_name();
            }

            inline path root_directory() const
            {
                return filesystem::path::root_directory();
            }

            inline path root_path() const
            {
                return filesystem::path::root_path();
            }

            inline path relative_path() const
            {
                return filesystem::path::relative_path();
            }

            inline path parent_path() const
            {
                return filesystem::path::parent_path();
            }

            path& operator=(path&& p) noexcept
            {
                return static_cast<path &>(static_cast<filesystem::path &>(*this) = std::move(p));
            }

            path& operator=(const path& p)
            {
                return static_cast<path &>(static_cast<filesystem::path &>(*this) = p);
            }

            path& operator=(filesystem::path&& p) noexcept
            {
                return static_cast<path &>(static_cast<filesystem::path &>(*this) = std::move(p));
            }

            path& operator=(const filesystem::path& p)
            {
                return static_cast<path &>(static_cast<filesystem::path &>(*this) = p);
            }
        };
        
        class directory_entry : public filesystem::directory_entry
        {
        public:
            using filesystem::directory_entry::directory_entry;

            inline operator const u8filesystem::path&() const noexcept
            {
                return static_cast<const u8filesystem::path &>(filesystem::directory_entry::operator const filesystem::path &());
            }

            inline const u8filesystem::path& path() const noexcept
            {
                return static_cast<const u8filesystem::path &>(filesystem::directory_entry::path());
            }
        };

        class directory_iterator : public filesystem::directory_iterator
        {
        public:
            typedef directory_entry value_type;
            typedef const value_type *pointer;
            typedef const value_type &reference;

        public:
            using filesystem::directory_iterator::directory_iterator;

            inline const value_type& operator*() const
            {
                return static_cast<const value_type &>(filesystem::directory_iterator::operator*());
            }

            inline directory_iterator& operator++()
            {
                return static_cast<directory_iterator &>(filesystem::directory_iterator::operator++());
            }

            inline pointer operator->() const
            {
                return static_cast<pointer>(filesystem::directory_iterator::operator->());
            }
        };

        inline bool exists(const path& p)
        {
            return filesystem::exists(p);
        }

        inline bool exists(const path& p, error_code& ec)
        {
            return filesystem::exists(p, ec);
        }

        inline bool create_directory(const path& p)
        {
            return filesystem::create_directory(p);
        }

        inline void resize_file(const path& p, uintmax_t newsize)
        {
            return filesystem::resize_file(p, newsize);
        }

        inline uintmax_t remove(const path& p)
        {
            return filesystem::remove(p);
        }

        inline uintmax_t remove_all(const path& p)
        {
            return filesystem::remove_all(p);
        }

        inline void rename(const path& oldp, const path& newp)
        {
            filesystem::rename(oldp, newp);
        }

        inline void copy(const path& oldp, const path& newp)
        {
            filesystem::copy(oldp, newp);
        }

        inline void copy(const path& oldp, const path& newp, copy_options opts)
        {
            filesystem::copy(oldp, newp, opts);
        }

        // Needed for range-based for loop
        inline const directory_iterator& begin(const directory_iterator& iter) noexcept
        {
            return iter;
        }

        // Needed for range-based for loop
        inline directory_iterator end(const directory_iterator&) noexcept
        {
            return directory_iterator();
        }

        inline path operator/(const path& left, const path& right)
        {
            return filesystem::operator/(left, right);
        }
#else
        using namespace filesystem;
#endif
    }
}
