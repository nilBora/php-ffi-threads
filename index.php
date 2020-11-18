<?php


include_once "ThreadFFI.php";

$thread = new ThreadFFI();

$thread->add(function($index) {
    echo "Thread {$index} Start\n";
    for ($i=0; $i<= 10; $i++) {
        echo "Thread: {$index}. Index: {$i}\n";
    }
    echo "Thread {$index} End\n";
});

$thread->add(function($index) {
    echo "Thread {$index} Start\n";
    for ($i=0; $i<= 10; $i++) {
        echo "Thread: {$index}. Index: {$i}\n";
    }
    echo "Thread {$index} End\n";
});

$thread->start();
