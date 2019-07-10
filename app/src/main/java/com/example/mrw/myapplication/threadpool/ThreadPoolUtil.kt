package com.example.mrw.myapplication.threadpool

class ThreadPoolUtil : Runnable {
    var str = ""

    constructor(str: String) {
        this.str = str
    }

    override fun run() {
        System.out.println("执行executors========$str")
    }

}