# DesignPatternByCpp

通过 C++ 实现 23 种经典设计模式，包含示例代码、UML 图、学习笔记等，便于系统学习和查阅。

## 目录结构

- [创建型模式](#创建型模式)
  - [01. 简单工厂（Simple Factory）](#01-简单工厂simple-factory)
  - [02. 工厂方法（Factory Method）](#02-工厂方法factory-method)
  - [03. 抽象工厂（Abstract Factory）](#03-抽象工厂abstract-factory)
  - [04. 建造者（Builder）](#04-建造者builder)
  - [05. 原型（Prototype）](#05-原型prototype)
  - [06. 单例（Singleton）](#06-单例singleton)
- [结构型模式](#结构型模式)
  - [07. 适配器（Adapter）](#07-适配器adapter)
  - [08. 桥接（Bridge）](#08-桥接bridge)
  - [09. 组合（Composite）](#09-组合composite)
  - [10. 装饰器（Decorator）](#10-装饰器decorator)
  - [11. 外观（Facade）](#11-外观facade)
  - [12. 享元（Flyweight）](#12-享元flyweight)
  - [13. 代理（Proxy）](#13-代理proxy)
- [行为型模式](#行为型模式)
  - [14. 职责链（Chain of Responsibility）](#14-职责链chain-of-responsibility)
  - [15. 命令（Command）](#15-命令command)
  - [16. 解释器（Interpreter）](#16-解释器interpreter)
  - [17. 迭代器（Iterator）](#17-迭代器iterator)
  - [18. 中介者（Mediator）](#18-中介者mediator)
  - [19. 备忘录（Memento）](#19-备忘录memento)
  - [20. 观察者（Observer）](#20-观察者observer)
  - [21. 状态（State）](#21-状态state)
  - [22. 策略（Strategy）](#22-策略strategy)
  - [23. 模板方法（Template Method）](#23-模板方法template-method)
  - [24. 访问者（Visitor）](#24-访问者visitor)

---

## 创建型模式

### 01. 简单工厂（Simple Factory）
- **定义**：由工厂类决定创建哪种产品对象，客户端只需传递参数即可获得对应实例。
- **适用场景**：产品种类较少，工厂逻辑简单。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/01.SampleFactory/)

### 02. 工厂方法（Factory Method）
- **定义**：定义一个用于创建对象的接口，让子类决定实例化哪一个类。
- **优点**：符合开闭原则，新增产品时无需修改工厂类。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/02.FactoryMethod/)

### 03. 抽象工厂（Abstract Factory）
- **定义**：提供一个接口，创建一系列相关或相互依赖的对象，无需指定具体类。
- **适用场景**：产品族扩展，多个产品等级。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/03.AbstractFactory/)

### 04. 建造者（Builder）
- **定义**：将复杂对象的构建与表示分离，同样的构建过程可创建不同表示。
- **适用场景**：产品内部结构复杂，构建过程独立于表示。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/04.BuilderPattern/)

### 05. 原型（Prototype）
- **定义**：通过复制已有实例来创建新对象，而不是通过 new。
- **优点**：高效创建复杂对象，避免重复初始化。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/05.PrototypePattern/)

### 06. 单例（Singleton）
- **定义**：保证一个类只有一个实例，并提供全局访问点。
- **应用**：配置管理、线程池、日志对象等。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/06.Singleton/)

---

## 结构型模式

### 07. 适配器（Adapter）
- **定义**：将一个类的接口转换为客户期望的另一个接口。
- **应用**：系统集成、兼容旧接口。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/07.AdapterPattern/)

### 08. 桥接（Bridge）
- **定义**：将抽象与实现分离，使其可以独立变化。
- **应用**：多维度变化的系统。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/08.BridgePattern/)

### 09. 组合（Composite）
- **定义**：将对象组合成树形结构以表示部分-整体层次。
- **应用**：树形菜单、文件系统。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/09.CompositePattern/)

### 10. 装饰器（Decorator）
- **定义**：动态地给对象添加额外职责，比生成子类更灵活。
- **应用**：IO流、功能扩展。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/10.Decorator/)

### 11. 外观（Facade）
- **定义**：为子系统提供统一接口，简化调用。
- **应用**：简化复杂系统接口。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/11.FacadePattern/)

### 12. 享元（Flyweight）
- **定义**：共享细粒度对象，节省内存。
- **应用**：大量相似对象场景。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/12.FlyweightPattern/)

### 13. 代理（Proxy）
- **定义**：为其他对象提供代理以控制访问。
- **应用**：远程代理、安全代理、延迟加载。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/13.ProxyPattern/)

---

## 行为型模式

### 14. 职责链（Chain of Responsibility）
- **定义**：使多个对象有机会处理请求，形成链，沿链传递直到被处理。
- **应用**：事件处理、审批流。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/14.ChainOfResponsibility/)

### 15. 命令（Command）
- **定义**：将请求封装为对象，支持撤销、重做。
- **应用**：事务、操作日志。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/15.CommandPattern/)

### 16. 解释器（Interpreter）
- **定义**：为语言创建解释器，定义文法并解释句子。
- **应用**：编译器、表达式计算。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/16.InterpreterPattern/)

### 17. 迭代器（Iterator）
- **定义**：顺序访问集合元素，无需暴露内部结构。
- **应用**：容器遍历。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/17.IteratorPattern/)

### 18. 中介者（Mediator）
- **定义**：用中介对象封装对象间交互，减少耦合。
- **应用**：聊天室、控件协作。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/18.MediatorPattern/)

### 19. 备忘录（Memento）
- **定义**：保存和恢复对象状态。
- **应用**：撤销、恢复。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/19.MementoPattern/)

### 20. 观察者（Observer）
- **定义**：对象间一对多依赖，状态变化自动通知。
- **应用**：事件监听、订阅发布。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/20.ObserverPattern/)

### 21. 状态（State）
- **定义**：对象行为随状态改变而改变。
- **应用**：状态机、流程控制。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/21.StatePattern/)

### 22. 策略（Strategy）
- **定义**：定义一系列算法，互换使用。
- **应用**：排序、加密算法。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/22.StrategyPattern/)

### 23. 模板方法（Template Method）
- **定义**：定义算法骨架，子类实现具体步骤。
- **应用**：通用流程、代码复用。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/23.TemplateMethodPattern/)

### 24. 访问者（Visitor）
- **定义**：对对象结构中的元素进行操作，解耦数据结构与操作。
- **应用**：编译器、对象结构遍历。
- **示例**：[代码 & 笔记](./Advanced%20Learning/设计模式/24.VisitorPattern/)

---

## 如何运行示例代码

1. 安装 CMake 和支持 C++11 及以上的编译器
2. 进入对应设计模式文件夹
3. 执行如下命令编译并运行示例
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ./main
   ```

## 参考资料

- 《设计模式：可复用面向对象软件的基础》GoF
- refactoring.guru/design-patterns
- 菜鸟教程、极客时间等
