#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = str;
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*ptr == c) {
      res = 1;
      break;
    }
    ptr++;
  }
  if (res == 0) {
    ptr = s21_NULL;
  }
  return (char *)ptr;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ptr1 = str1, *ptr2 = str2;
  while (n--) {
    if (*ptr1 != *ptr2) {
      return *ptr1 - *ptr2;
    }
    ptr1++;
    ptr2++;
  }
  return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; ++i) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = str;
  unsigned char ch = c;
  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = ch;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  while (*ptr != '\0') {
    ptr++;
  }
  s21_size_t src_len = s21_strlen(src);
  s21_size_t min_len;
  if (src_len < n) {
    min_len = src_len;
  } else {
    min_len = n;
  }
  if ((ptr - dest) + min_len >= sizeof(dest)) {
      return s21_NULL;
  }
  for (s21_size_t i = 0; i < min_len; i++) {
    ptr[i] = src[i];
  }
  ptr[min_len] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *letter = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
    if (*(str + i) == c) {
      letter = (char *)(str + i);
      break;
    }
  }
  return letter;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    s21_size_t size = s21_strlen(str1) + 1;
    if (size > s21_strlen(str2) + 1) {
        size = s21_strlen(str2) + 1;
    }
    if (size > n) {
        size = n;
    }
    return s21_memcmp((const void *)str1, (const void *)str2, size);
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int fl = 0;
  s21_size_t res = s21_strlen(str1);
  for (s21_size_t i = 0; i < s21_strlen(str1) && fl == 0; i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2) && fl == 0; j++) {
      if (*(str1 + i) == *(str2 + j)) {
        fl = 1;
        res = i;
      }
    }
  }
  return res;
}

char *s21_strcat(char *dest, const char *src) {
  char *begin = dest;
  while (*begin != '\0')
    begin++;
  while (*src != '\0') {
    *begin = *src;
    begin++;
    src++;
  }
  *begin = '\0';
  return dest;
}

char *s21_strcpy(char *dest, const char *src) {
  char *dest1 = dest;
  while (*src) {
    *(dest++) = *(src++);
  }
  *dest = '\0';
  return dest1;
}

#define ERROR "Unknown error"

#if defined(__APPLE__) || defined(__MACH__)
#define s21_ERRLIST_SIZE 107
static const char *const s21_sys_errlist[s21_ERRLIST_SIZE] = {
    [0] = "Undefined error: 0",
    [1] = "Operation not permitted",
    [2] = "No such file or directory",
    [3] = "No such process",
    [4] = "Interrupted system call",
    [5] = "Input/output error",
    [6] = "Device not configured",
    [7] = "Argument list too long",
    [8] = "Exec format error",
    [9] = "Bad file descriptor",
    [10] = "No child processes",
    [11] = "Resource deadlock avoided",
    [12] = "Cannot allocate memory",
    [13] = "Permission denied",
    [14] = "Bad address",
    [15] = "Block device required",
    [16] = "Resource busy",
    [17] = "File exists",
    [18] = "Cross-device link",
    [19] = "Operation not supported by device",
    [20] = "Not a directory",
    [21] = "Is a directory",
    [22] = "Invalid argument",
    [23] = "Too many open files in system",
    [24] = "Too many open files",
    [25] = "Inappropriate ioctl for device",
    [26] = "Text file busy",
    [27] = "File too large",
    [28] = "No space left on device",
    [29] = "Illegal seek",
    [30] = "Read-only file system",
    [31] = "Too many links",
    [32] = "Broken pipe",
    [33] = "Numerical argument out of domain",
    [34] = "Result too large",
    [35] = "Resource temporarily unavailable",
    [36] = "Operation now in progress",
    [37] = "Operation already in progress",
    [38] = "Socket operation on non-socket",
    [39] = "Destination address required",
    [40] = "Message too long",
    [41] = "Protocol wrong type for socket",
    [42] = "Protocol not available",
    [43] = "Protocol not supported",
    [44] = "Socket type not supported",
    [45] = "Operation not supported",
    [46] = "Protocol family not supported",
    [47] = "Address family not supported by protocol family",
    [48] = "Address already in use",
    [49] = "Can't assign requested address",
    [50] = "Network is down",
    [51] = "Network is unreachable",
    [52] = "Network dropped connection on reset",
    [53] = "Software caused connection abort",
    [54] = "Connection reset by peer",
    [55] = "No buffer space available",
    [56] = "Socket is already connected",
    [57] = "Socket is not connected",
    [58] = "Can't send after socket shutdown",
    [59] = "Too many references: can't splice",
    [60] = "Operation timed out",
    [61] = "Connection refused",
    [62] = "Too many levels of symbolic links",
    [63] = "File name too long",
    [64] = "Host is down",
    [65] = "No route to host",
    [66] = "Directory not empty",
    [67] = "Too many processes",
    [68] = "Too many users",
    [69] = "Disc quota exceeded",
    [70] = "Stale NFS file handle",
    [71] = "Too many levels of remote in path",
    [72] = "RPC struct is bad",
    [73] = "RPC version wrong",
    [74] = "RPC prog. not avail",
    [75] = "Program version wrong",
    [76] = "Bad procedure for program",
    [77] = "No locks available",
    [78] = "Function not implemented",
    [79] = "Inappropriate file type or format",
    [80] = "Authentication error",
    [81] = "Need authenticator",
    [82] = "Device power is off",
    [83] = "Device error",
    [84] = "Value too large to be stored in data type",
    [85] = "Bad executable (or shared library)",
    [86] = "Bad CPU type in executable",
    [87] = "Shared library version mismatch",
    [88] = "Malformed Mach-o file",
    [89] = "Operation canceled",
    [90] = "Identifier removed",
    [91] = "No message of desired type",
    [92] = "Illegal byte sequence",
    [93] = "Attribute not found",
    [94] = "Bad message",
    [95] = "EMULTIHOP (Reserved)",
    [96] = "No message available on STREAM",
    [97] = "ENOLINK (Reserved)",
    [98] = "No STREAM resources",
    [99] = "Not a STREAM",
    [100] = "Protocol error",
    [101] = "STREAM ioctl timeout",
    [102] = "Operation not supported on socket",
    [103] = "Policy not found",
    [104] = "State not recoverable",
    [105] = "Previous owner died",
    [106] = "Interface output queue is full"};
#endif

#if defined(__linux__)
#define s21_ERRLIST_SIZE 134
static const char *const s21_sys_errlist[s21_ERRLIST_SIZE] = {
    [0] = "Success",
    [1] = "Operation not permitted",
    [2] = "No such file or directory",
    [3] = "No such process",
    [4] = "Interrupted system call",
    [5] = "Input/output error",
    [6] = "No such device or address",
    [7] = "Argument list too long",
    [8] = "Exec format error",
    [9] = "Bad file descriptor",
    [10] = "No child processes",
    [11] = "Resource temporarily unavailable",
    [12] = "Cannot allocate memory",
    [13] = "Permission denied",
    [14] = "Bad address",
    [15] = "Block device required",
    [16] = "Device or resource busy",
    [17] = "File exists",
    [18] = "Invalid cross-device link",
    [19] = "No such device",
    [20] = "Not a directory",
    [21] = "Is a directory",
    [22] = "Invalid argument",
    [23] = "Too many open files in system",
    [24] = "Too many open files",
    [25] = "Inappropriate ioctl for device",
    [26] = "Text file busy",
    [27] = "File too large",
    [29] = "No space left on device",
    [30] = "Illegal seek",
    [31] = "Read-only file system",
    [32] = "Too many links",
    [33] = "Broken pipe",
    [34] = "Numerical argument out of domain",
    [35] = "Numerical result out of range",
    [36] = "Resource deadlock avoided",
    [37] = "File name too long",
    [38] = "No locks available",
    [39] = "Function not implemented",
    [40] = "Directory not empty",
    [41] = "Too many levels of symbolic links",
    [42] = "Unknown error 41",
    [43] = "No message of desired type",
    [44] = "Identifier removed",
    [45] = "Channel number out of range",
    [46] = "Level 2 not synchronized",
    [47] = "Level 3 halted",
    [48] = "Level 3 reset",
    [49] = "Link number out of range",
    [50] = "Protocol driver not attached",
    [51] = "No CSI structure available",
    [52] = "Level 2 halted",
    [53] = "Invalid exchange",
    [54] = "Invalid request descriptor",
    [55] = "Exchange full",
    [56] = "No anode",
    [57] = "Invalid request code",
    [58] = "Invalid slot",
    [59] = "Unknown error 58",
    [60] = "Bad font file format",
    [61] = "Device not a stream",
    [62] = "No data available",
    [63] = "Timer expired",
    [64] = "Out of streams resources",
    [65] = "Machine is not on the network",
    [66] = "Package not installed",
    [67] = "Object is remote",
    [68] = "Link has been severed",
    [69] = "Advertise error",
    [70] = "Srmount error",
    [71] = "Communication error on send",
    [72] = "Protocol error",
    [73] = "Multihop attempted",
    [74] = "RFS specific error",
    [75] = "Bad message",
    [76] = "Value too large for defined data type",
    [77] = "Name not unique on network",
    [78] = "File descriptor in bad state",
    [79] = "Remote address changed",
    [80] = "Can not access a needed shared library",
    [81] = "Accessing a corrupted shared library",
    [82] = ".lib section in exrcutable file is corrupted",
    [83] = "Attempting to link in too many shared libraries",
    [84] = "Invalid or incomplete multibyte or wide character",
    [85] = "Interrupted system call should be restarted",
    [86] = "Streams pipe error",
    [87] = "Too many users",
    [88] = "Socket operation on non-socket",
    [89] = "Destination address required",
    [90] = "Message too long",
    [91] = "Protocol wrong type for socket",
    [92] = "Protocol not available",
    [93] = "Protocol not supported",
    [94] = "Socket type not supported",
    [95] = "Operation not supported",
    [96] = "Protocol family not supported",
    [97] = "Address family not supported by protocol",
    [98] = "Address already in use",
    [99] = "Cannot assign requested address",
    [100] = "Network is down",
    [101] = "Network is unreachable",
    [102] = "Network dropped connection on reset",
    [103] = "Software caused connection abort",
    [104] = "Connection reset by peer",
    [105] = "No buffer space available",
    [106] = "Transport endpoint is already connected",
    [107] = "Transport endpoint is not connected",
    [108] = "Cannot send after transport endpoint shutdown",
    [109] = "Too many references: cannot splice",
    [110] = "Connection timed out",
    [111] = "Connection refused",
    [112] = "Host is down",
    [113] = "No route to host",
    [114] = "Operation already in progress",
    [115] = "Operation now in progress",
    [116] = "Stale file handle",
    [117] = "Structure needs cleaning",
    [118] = "Not a XENIX named type file",
    [119] = "No XENIX semaphores available",
    [120] = "Is a named type file",
    [121] = "Remote I/O error",
    [122] = "Disk quota exceeded",
    [123] = "No medium found",
    [124] = "Wrong medium type",
    [125] = "Operation canceled",
    [126] = "Required key not available",
    [127] = "Key has expired",
    [128] = "Key has been revoked",
    [129] = "Key was rejected by service",
    [130] = "Owner died",
    [131] = "State not recoverable",
    [132] = "Operation not possible due to RF-kill",
    [133] = "Memory page has hardware error",
};
#endif

char *s21_strerror(int errnum) {
  static char res[1024] = {"\0"};
  if (errnum < 0 || errnum >= s21_ERRLIST_SIZE) {
    sprintf(res, "%s: %d", ERROR, errnum); // change it?
  } else {
    s21_strcpy(res, s21_sys_errlist[errnum]);
  }
  return res;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;
  if (str != s21_NULL) {
    for (s21_size_t i = 0; str[i] != 0; i++) {
      result++;
    }
  }
  return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  for (char *ptr = (char *)str1; *ptr != '\0' && result == s21_NULL; ptr++) {
    for (char *ptr2 = (char *)str2; *ptr2 != '\0'; ptr2++) {
      if (*ptr == *ptr2) {
        result = ptr;
        break;
      }
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  for (s21_size_t i = s21_strlen(str); i > 0; i--) {
    if (str[i] == c) {
      result = (char *)(str + i);
      break;
    }
  }
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == s21_NULL || needle == s21_NULL) {
    return s21_NULL;
  }
  char *res = s21_NULL;
  for (s21_size_t i = 0; res == s21_NULL && haystack[i] != '\0'; i++) {
    s21_size_t j = 0;
    while (haystack[i + j] == needle[j] && needle[j] != '\0') {
      j++;
      }
    if (needle[j] == '\0') {
      res = (char *)&haystack[i];
    }
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *tmp = s21_NULL;
  if (str) {
    tmp = str;
    while (*tmp && s21_strrchr(delim, *tmp)) {
      tmp++;
    }
  }
  if (tmp) {
    if (*tmp) {
      str = tmp;
      while (s21_strrchr(delim, *str)) {
        str++;
        tmp++;
      }
      while (*tmp && !s21_strrchr(delim, *tmp)) {
        tmp++;
      }
      if (*tmp && s21_strrchr(delim, *tmp)) {
        *tmp++ = 0;
      }
    } else {
      str = s21_NULL;
    }
  } else {
    str = s21_NULL;
  }
  return str;
}

void *s21_to_upper(const char *str) {
    char *Upstr = s21_NULL;
    s21_size_t lenght = 0;
    if (str != s21_NULL) {
        lenght = s21_strlen(str);
        Upstr = malloc(sizeof(char) * lenght + 1);
    }
    if (Upstr != s21_NULL) {
        for (s21_size_t i = 0; i < lenght; i++) {
            if (str[i] >= 97 && str[i] <= 122) {
                Upstr[i] = str[i] - 32;
            } else {
                Upstr[i] = str[i];
            }
        }
    }
    return Upstr;
}

void *s21_to_lower(const char *str) {
    s21_size_t lenght = 0;
    char *lowstr = s21_NULL;
    if (str != s21_NULL) {
        lenght = s21_strlen(str);
        lowstr = malloc(sizeof(char) * lenght + 1);
    }
    if (lowstr != s21_NULL) {
        for (s21_size_t i = 0; i < lenght; i++) {
            if (str[i] >= 65 && str[i] <= 90) {
                lowstr[i] = str[i] + 32;
            } else {
                lowstr[i] = str[i];
            }
        }
    }
    return lowstr;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    s21_size_t z = 0;
    char *newstr = s21_NULL;
    s21_size_t lenght = 0;
    if (src != s21_NULL && str != s21_NULL) {
        if (start_index <= s21_strlen(src)) {
            lenght = s21_strlen(str) + s21_strlen(src) + 1;
            newstr = malloc(sizeof(char) * lenght);
        }
    }
    if (newstr != s21_NULL) {
        for (s21_size_t i = 0; i < lenght; i++) {
            if (i == start_index)
                for (s21_size_t y = 0; y < s21_strlen(str); y++)
                    newstr[i++] = str[y];
            newstr[i] = src[z++];
        }
        newstr[lenght - 1] = '\0';
    }
    return newstr;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *strtrim = s21_NULL;
    if (src != s21_NULL) {
        int y = 0;
        s21_size_t start = 0;
        s21_size_t lenght = s21_strlen(src);
        s21_size_t end = lenght;
        for (s21_size_t i = 0; i < lenght; i++) {
            if (s21_strchr(trim_chars, src[i]) != s21_NULL && start == i) {
                start++;
            }
            if (s21_strchr(trim_chars, src[lenght - i]) != s21_NULL && end == lenght - i) {
                end--;
            }
            if (start > end)
                break;
        }
        if (start <= end)
            strtrim = malloc(sizeof(char) * (end - start) + 1);
        if (strtrim != s21_NULL) {
            for (s21_size_t i = start; i <= end; i++)
                strtrim[y++] = src[i];
            strtrim[y] = '\0';
        } else if (start > end) {
            strtrim = malloc(sizeof(char));
            strtrim[0] = '\0';
        }
    }
    return strtrim;
}


