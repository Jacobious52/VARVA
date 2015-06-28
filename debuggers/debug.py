import inspect, math

def watch(key, val, note='""'):
    func = inspect.currentframe().f_back.f_code

    with open('%s.var' % key, 'a') as f:
        f.write("%f,%s,%s,%i,%s\n" % (val, func.co_filename.split('/')[-1], func.co_name, func.co_firstlineno, note))

def main():
    for i in range(0, 20):
        watch("i", float(math.sin(i)), '"note"')

    for i in range(0, 20):
        watch('x', float(2*i), '"x is now %s"' % i)

if __name__ == '__main__':
    main()
