# ColorCout
Simple cross-platform(?) colored terminal text in C++

## How to use

```cpp
int main() {
    ccout(YELLOW) << "Hello, World!" << ccendl;
    ccout(CYAN) << "Hello, World!" << ccendl;
    ccout(BLACK) << "Hello, World!" << ccendl;
    return 0;
}
```

![example](https://user-images.githubusercontent.com/12003087/78259083-c6a6ff80-752e-11ea-8d16-0a45fcc811c9.png)