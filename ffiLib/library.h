#define FFI_SCOPE "MYLIB"
#define BAD_MESSAGE "13"
#define SUCCESS 0
#define MAX_THREADS 5

typedef int (*callback_t)(int);

int start();
void* add(callback_t callback);

