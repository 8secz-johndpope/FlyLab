# K8s In Action

- k8s version: v1.17.0
- minkube v1.7.3

## 运行本地k8s环境

> [支持国内环境](https://yq.aliyun.com/articles/221687)

```bash
make start
```

___

# K8S镜像加速

### gcr.io镜像加速

- gcr.azk8s.cn/google-containers
- gcr.azk8s.cn

### quay.io镜像加速

- quay.azk8s.cn


## play minikube

```bash
minikube service -n namesapce servicename
```

```bash

## play minikube example
kubectl create deployment hello-node --image=gcr.azk8s.cn/hello-minikube-zero-install/hello-node

## 创建负载均衡器
kubectl expose deployment hello-node --type=LoadBalancer --port=8080
kubectl expose deployment kubernetes-dashboard --type=LoadBalancer --port=8443


## 查阅deployment
kubectl get deployment
kubectl get pods
kubectl get events

## 清理应用
kubectl delete service hello-node
kubectl delete deployment hello-node
```


## kubectl命令

```bash

## 获取所有service
kubectl get svc [serviceName]

## 获取 service 生成的yaml
kubectl get svc [serviceName] -o yaml

```


## 常见异常

```
Error creating: pods "dashboard-metrics-scraper-7b64584c5c-" is forbidden: error looking up service account kubernetes-dashboard/kubernetes-dashboard: serviceaccount "kubernetes-dashboard" not found
```

## 运行状态查看

```bash
 kubectl get pods -A
```

## 工具

- [K8s 客户端](https://kubernetic.com/)

## [把应用程序迁移到k8s需要修改什么？](https://blog.csdn.net/weixin_38748858/article/details/102758381)

## [docker.io、gcr.io、quay.io镜像加速](https://www.ilanni.com/?p=14534)

## Refers

- [k8s tutorials](https://kubernetes.io/zh/docs/tutorials/stateless-application/expose-external-ip-address/)
- [谷歌云台](https://console.cloud.google.com/freetrial?pli=1)
- [Kubernetes Cookbook: Building Cloud Native Applications](https://books.google.com.hk/books?id=QBlMDwAAQBAJ&dq=minikube+dashboard+without+using+addons&hl=zh-CN)
- [镜像源加速工具](https://github.com/xuxinkun/littleTools#azk8spull)