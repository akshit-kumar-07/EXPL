class A:
    def f0(self):
        print("In class A f0")
        return 1

    def f1(self):
        print("In class A f1")
        return 1

    def f(self, x, y):
        return x

class B(A):
    def f0(self):
        print("In class B f0")
        return 1

    def f2(self):
        print("In class B f2")
        return 1

    def f(self, x, y):
        return y

class C(B):
    def f0(self):
        print("In class C f0")
        return 1

    def f2(self):
        print("In class C f2")
        return 1

    def f4(self):
        print("In class C f4")
        return 1

    def f(self, x, y):
        if y == 0:
            val = x
        else:
            val = self.g(self.f(x - 1, y - 1), y - 1)
        return val

    def g(self, x, y):
        if y == 0:
            val = x
        else:
            val = self.f(self.g(x - 1, y - 1), y - 1)
        return val

obj = None
test_obj = None

def initialize():
    pass

def read():
    return int(input())

def new(cls):
    return cls()

def write(value):
    print(value)

def main():
    global obj, test_obj
    initialize()
    n = read()
    if n < 0:
        obj = new(A)
    elif n == 0:
        obj = new(B)
    elif n > 0:
        obj = new(C)
    
    test_obj = obj
    x = 10
    y = 12

    write(test_obj.f(x, y))

if __name__ == "__main__":
    main()

