# Docker

<img src="https://www.docker.com/wp-content/uploads/2023/08/logo-guide-logos-1.svg" title="Docker Logo" style="width: 50%;" align="right">

## What is Docker?

Docker is a platform for developing, shipping, and running applications in containers. Containers allow a developer to package up an application with all of the parts it needs, such as libraries and other dependencies, and ship it all out as one package. By doing so, thanks to the container, the developer can rest assured that the application will run on any other Linux machine regardless of any customized settings that machine might have that could differ from the machine used for writing and testing the code.

### Docker vs Virtual Machines

- Virtual machines (VMs) are an abstraction of physical hardware turning one server into many servers. The hypervisor allows multiple VMs to run on a single machine. Each VM includes a full copy of an operating system, the application, necessary binaries, and libraries - taking up tens of GBs. VMs can also be slow to boot.

- Containers take a different approach, by leveraging the low-level mechanics of the host operating system. Containers are lightweight and fast to boot. Containers share the host OS kernel and are isolated in user space. They can also be run on any computer and any infrastructure.

[🎬 Docker Guide (Portainer as example) - Chris Titus Tech](https://christitus.com/docker-guide/)

## Install Docker

🔗 [Official Docker - Install on Debian](https://docs.docker.com/engine/install/debian/#install-using-the-repository)

## PID 1

🔗 [PID 1 - Why do you need an init process inside your Docker container (PID 1)](https://daveiscoding.hashnode.dev/why-do-you-need-an-init-process-inside-your-docker-container-pid-1)

🔗 [PID 1 - Docker processes container](https://cloud.theodo.com/en/blog/docker-processes-container)
