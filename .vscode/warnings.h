// disables the "too many characters in character constant" intellisense error, because we have u64 constants all over the place
#pragma diag_suppress 26

// disables the "invalid multibyte character sequence" error since we have to escape shift-jis misreads a lot
#pragma diag_suppress 870

// disables the "invalid arguments for operator new" error
#pragma diag_suppress 1767

// disables the "first parameter of allocation function must be of type 'size_t" error
#pragma diag_suppress 351

// disables the "initial value of reference to non-const must be an lvalue" error
#pragma diag_suppress 461
