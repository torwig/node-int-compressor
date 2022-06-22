# integer-compression
JS bindings to C++ compression methods

## Clone

```sh
git clone git@github.com:torwig/integer-compression.git
git submodule update --init compression
```

## Build

```sh
cd compression
make libic.a
cd ..
npm install
```

## Rebuild
```sh
node-gyp rebuild
```

## Run
```sh
node addon.js
```
