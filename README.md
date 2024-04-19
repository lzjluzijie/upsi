# upsi

## Build

This project depends on `boost` and `libOTe`. The author used `gcc 12.2.0`.

```shell
cd libOTe
python build.py --all --boost --sodium
cd .. 
mkdir build
cd build
cmake ..
make -j
```

To run it: 
```shell
./upsi -r 2 
```

## Contact

Contact `lzjluzijie@gmail.com` if you have any question.
