# Infrastructure as Code

## Ressources

- [Terraform](https://www.terraform.io/)
- [Ansible](https://www.ansible.com/)
- [AWS](https://aws.amazon.com/)
- [Azure](https://azure.microsoft.com/)
- [Google Cloud](https://cloud.google.com/)

### Localy learn infrastructure as code

Use kubernetes to deploy a local cluster and deploy services on it.
- [Minikube](https://minikube.sigs.k8s.io/docs/)

#### Advices

- Learn by using a sandbox environment of public cloud providers
  - Use a cloud provider to deploy a cluster and deploy services on it
- Watch out for the cost of the resources you deploy
  - Use the free tier of the cloud provider
  - The cost of the resources can be high if you don't pay attention (presenter had a bill of 500$ because of a misconfiguration and it can be worse...)

### Roadmap

- [DevOps Roadmap - With steps provide by presenter](https://roadmap.sh/devops?ref=hackernoon.com)

## History of System Administration

- Manual System Administration with bare metal servers
- Virtualization with DevOps
  - CICD: Continuous Integration and Continuous Deployment
- Cloud Computing
  - AWS, Azure, Google Cloud
  - Adaptative compute power according to demand
  - Expensive but efficient
- Loads of instances to manage
  - Infrastructure as Code - IaC to manage them (by DevOps)

## Terraform

Terrafom is a tool for building, changing, and versioning infrastructure safely and efficiently. It can manage existing and popular service providers as well as custom in-house solutions.

It's a stateful tool that can manage the state of the infrastructure.

### Terraform Configuration

- Configuration files describe to Terraform the components needed to run a single application or your entire datacenter.

- The configuration is written in HashiCorp Configuration Language (HCL) or JSON.

- The configuration files can be organized into modules.

- The configuration files describe the relationships between components.

### Terraform Workflow

1. **Write**: Author infrastructure as code
2. **Plan**: Preview changes before applying
3. **Apply**: Provision reproducible infrastructure
4. **Destroy**: De-provision resources

### Use Cases

- Create multiple servers in parallel
- Deploy a containerized application
- Monitor and alert on resources status

### Terraform State

Compares the current state of the infrastructure with the desired state. It is stored in a file named `terraform.tfstate`.

Useful for:
- Tracking metadata
- Performance optimization
- Resource management

## Ansible

Ansible is an open-source automation tool, or platform, used for IT tasks such as configuration management, application deployment, intraservice orchestration, and provisioning.

Ansible is stateless and sends commands to nodes through SSH.

### Ansible Playbooks

- Playbooks are Ansible’s configuration, deployment, and orchestration language.

- They can describe a policy you want your remote systems to enforce, or a set of steps in a general IT process.

- Playbooks are designed to be human-readable and are developed in a basic text language.
  - In YAML format

### Portability

Can be run from CICD tools like Jenkins, GitLab, etc.

## Infrastructure

### Examples

From Github repositories:

- Github Actions
1. OpenID Connect (OIDC) authentication
2. Terraform tasks to create resources(VMs, VPCs, etc.) with configure providers
  2.1. Terraform tasks to create resources(VMs, VPCs, etc.)
  2.2. Terraform manage volumes, etc. (s3 backend, etc.)

3. Ansible tasks to configure resources(Install software, etc.)
4. Monitoring tasks to monitor resources
  4.1. Terraform verify the state of the resources 

## Security

Prevent access to AWS CLI as much as possible.