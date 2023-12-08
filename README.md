# Mockingjay
Mimicking of Belady's min algorithm
##### 1. Apply a path file for cse server

```
$ git apply cse_server.patch
```

##### 2. Unzip benchmarks files

```
zip -F benchmarks.zip --out single-benchmark.zip && unzip single-benchmark.zip && mkdir benchmarks/parsec-2.1/inputs/streamcluster
```

### 3. Environment setup

Everytime you want to build or run zsim, you need to setup the environment variables first.

```
$ source setup_env
```

##### 4. Compile zsim

```
$ cd zsim
$ scons -j4
```

##### 5. Launch a test to run

```
$ ./term_project_runscript <suite> <benchmark> <repl_policy>
```



###### For more information, check `zsim/README.md`
