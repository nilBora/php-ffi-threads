# FFI Thread

## First Step
Generate `so` lib file width sources. Run command

`make build`

After this command in lib directory will be created to files `library.o` and `library.so`

File `library.so` we include in class `ThreadFFI`

## Use
```php
$thread = new ThreadFFI();

$thread->add(function($index) {
    // You Callback Function
});

$thread->add(function($index) {
    // You Callback Function
});

$thread->start();
```

## Conclusion
If use a lot of calculations we got error `segmentation fault`. Bad realization(;
