<h1 align="center">
	🗣️ minitalk
</h1>

<p align="center">
	<b><i>A signal project</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about-the-project">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-how-to-use-minitalk">How to use minitalk</a>
</h3>

---

## 💡 About the project

> _The purpose of this project is to code a small data exchange program using
UNIX signals._


## 🛠️ How to use minitalk

### Requirements

In order to run minitalk you will need **make**, the  **`cc` compiler** and the standard **C libraries**.

### Instructions

**1. Compiling**

In order to compile, go to the project path and run:

```sh
make
```
**2. Execute binaries**

>To test the program you need to launch the ***server*** and the ***client*** binaries in different shell tabs.

#### 2.1 ) Run server
```sh
./bin/server
```
>This will instanciate and show your server's ***pid***. Then, the server will wait until it receives a message from the "client"

#### 2.1 ) Run client
```sh
$ ./bin/client "<pid>" "... some string..."
```
>This will show <*... some string...*> on the server's window.
