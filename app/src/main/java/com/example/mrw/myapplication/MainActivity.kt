package com.example.mrw.myapplication

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import com.example.mrw.myapplication.threadpool.ThreadPoolUtil
import kotlinx.android.synthetic.main.activity_main.*
import java.util.concurrent.Executors
import java.util.concurrent.ScheduledExecutorService
import java.util.concurrent.TimeUnit

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = getStringLengthNonStatic("").toString()

        exportArray(arrayOf("1", "3", "2","1", "3", "2"))
//        executors()
    }

    fun executors() {
        var sched: ScheduledExecutorService = Executors.newScheduledThreadPool(4)
//        sched.scheduleWithFixedDelay(ThreadPoolUtil("one"), 1,1, TimeUnit.SECONDS)
//        sched.scheduleWithFixedDelay(ThreadPoolUtil("two"), 1,1, TimeUnit.SECONDS)
        sched.scheduleAtFixedRate(ThreadPoolUtil("three"), 2, 3, TimeUnit.SECONDS)
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(str: String, num: Int): Boolean

    external fun getStrLength(str: String): Int

    external fun getStringLengthNonStatic(str: String): Int

    external fun exportArray(a: Array<String>)

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
