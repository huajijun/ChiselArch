lazy val hello = taskKey[Unit]("a test task")
lazy val root = (project in file("."))
    .settings(
        name := "ChiselArch",
        version := "1.0",
        scalaVersion := "2.12.14",
        hello := {println("hello task")}
    )
scalaVersion := "2.12.13"

crossScalaVersions := Seq("2.12.10", "2.11.12")
libraryDependencies += "edu.berkeley.cs" %% "chisel3" % "3.4.4"
libraryDependencies += "edu.berkeley.cs" %% "chisel-iotesters" % "1.5.3"
scalacOptions ++= Seq("-deprecation", "-feature", "-unchecked", "-language:reflectiveCalls", "-Xsource:2.11")
