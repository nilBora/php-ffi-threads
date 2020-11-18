<?php

class ThreadFFI
{
    protected $ffi;
    
    public function __construct()
    {
        if (!$this->_isExistFileLib())
        {
            throw new ThreadFfiException("File Lib Not Found");
        }
        $this->ffi = FFI::cdef('
            typedef int (*callback_t)(int);
            int start();
            void* add(callback_t callback);',
            $this->_getLibPath()
        );
    } // end __construct
    
    private function _isExistFileLib(): bool
    {
        return file_exists($this->_getLibPath());
    } // end _isExistFileLib
    
    private function _getLibPath(): string
    {
        return __DIR__.'/ffiLib/library.so'; // the path of our dll
    } // end _getLibPath
    
    public function add(Closure $callback)
    {
        $this->ffi->add($callback);
    } // end add
    
    public function start()
    {
        $this->ffi->start();
    } // end start
}

class ThreadFfiException extends Exception
{
}