# coding: utf-8
import time
import psutil
import multiprocessing

# affinity.set_process_affinity_mask(os.getpid(), 2L)

def make_usage(level):
    while True:
        if psutil.cpu_percent(interval=None) > level:
            time.sleep(0.01)


if __name__ == '__main__':
    p = multiprocessing.Pool()
    for i in range(0, psutil.cpu_count()):
        p.apply_async(make_usage, args=(50,))
        # p.apply_async(make_usage, args=(80,))
    p.close()
    p.join()
