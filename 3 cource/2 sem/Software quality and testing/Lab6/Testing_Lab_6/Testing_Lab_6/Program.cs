using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Loader;
using System.Xml;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.Emit;

namespace Testing_Lab_6
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Введите имя файла с кодом:");
            //string fileCode = Console.ReadLine();
            string fileCode = "Sum.cs";
            Console.WriteLine(fileCode);
            
            Console.WriteLine("Введите имя файла с тестами:");
            //string fileTests = Console.ReadLine();
            string fileTests = "tests.xml";
            Console.WriteLine(fileTests);

            string pathCode = "../../../" + fileCode;
            string pathTests = "../../../" + fileTests;

            string codeToCompile = "";

            try
            {
                using (StreamReader sr = new StreamReader(pathCode))
                {
                    codeToCompile = sr.ReadToEnd();
                    //Console.WriteLine(codeToCompile);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return;
            }
            

            #region string code example
            //string codeToCompile = @"
            //using System;
            //namespace RoslynCompileSample
            //{
            //    public class Writer
            //    {
            //        public void Write(string message)
            //        {
            //            Console.WriteLine($""you said '{message}!'"");
            //        }
            //    }
            //}";
            #endregion

            //Console.WriteLine("Parsing the code into the SyntaxTree");
            SyntaxTree syntaxTree = CSharpSyntaxTree.ParseText(codeToCompile);

            string assemblyName = Path.GetRandomFileName();
            var refPaths = new[] {
                typeof(object).GetTypeInfo().Assembly.Location,
                typeof(Console).GetTypeInfo().Assembly.Location,
                Path.Combine(Path.GetDirectoryName(typeof(System.Runtime.GCSettings).GetTypeInfo().Assembly.Location), "System.Runtime.dll")
            };
            MetadataReference[] references = refPaths.Select(r => MetadataReference.CreateFromFile(r)).ToArray();

            //Console.WriteLine("Adding the following references");
            //foreach (var r in refPaths)
            //    Console.WriteLine(r);

            Console.WriteLine("Compiling ...");
            CSharpCompilation compilation = CSharpCompilation.Create(
                assemblyName,
                syntaxTrees: new[] { syntaxTree },
                references: references,
                options: new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));

            using (var ms = new MemoryStream())
            {
                EmitResult result = compilation.Emit(ms);

                if (!result.Success)
                {
                    Console.WriteLine("Compilation failed!");
                    IEnumerable<Diagnostic> failures = result.Diagnostics.Where(diagnostic =>
                        diagnostic.IsWarningAsError ||
                        diagnostic.Severity == DiagnosticSeverity.Error);

                    foreach (Diagnostic diagnostic in failures)
                    {
                        Console.Error.WriteLine("\t{0}: {1}", diagnostic.Id, diagnostic.GetMessage());
                    }
                }
                else
                {
                    Console.WriteLine("Compilation successful! Now instantiating and executing the code ...");
                    ms.Seek(0, SeekOrigin.Begin);

                    Assembly assembly = AssemblyLoadContext.Default.LoadFromStream(ms);
                    var type = assembly.GetType("RoslynCompileSample.Sum");
                    var instance = assembly.CreateInstance("RoslynCompileSample.Sum");

                    XmlDocument xmlDocument = new XmlDocument();
                    xmlDocument.Load(pathTests);
                    XmlElement xRoot = xmlDocument.DocumentElement;

                    string functionName = "";
                    List<double> arguments = new List<double>() { 0, 0 };
                    double expectedValue = 0;
                    int testNumber = 1;

                    foreach(XmlNode test in xRoot)
                    {
                        foreach (XmlNode childNode in test)
                        {                            
                            if (childNode.Name == "function")
                            {
                                try
                                {
                                    functionName = childNode.InnerText;
                                    Console.WriteLine($"{testNumber}| F: {functionName}");
                                }
                                catch (Exception e)
                                {
                                    Console.WriteLine($"Faile on test {testNumber}: Incorrect/missed arguments/expected value \n " +
                                                    $"Message: {e.Message} \n" +
                                                    $"StackTrace: {e.StackTrace}\n" +
                                                    $"TargetSite: {e.TargetSite}");
                                    return;
                                }
                            }
                            if (childNode.Name == "arg1")
                            {
                                try
                                {
                                    arguments[0] = Convert.ToDouble(childNode.InnerText);
                                    Console.WriteLine($"{testNumber}| A1: {arguments[0]}");
                                }
                                catch (Exception e)
                                {
                                    Console.WriteLine($"Faile on test {testNumber}: Incorrect/missed arguments/expected value \n " +
                                                    $"Message: {e.Message} \n" +
                                                    $"StackTrace: {e.StackTrace}\n" +
                                                    $"TargetSite: {e.TargetSite}");
                                    return;
                                }
                            }
                            if (childNode.Name == "arg2")
                            {
                                try
                                {
                                    arguments[1] = Convert.ToDouble(childNode.InnerText);
                                    Console.WriteLine($"{testNumber}| A2: {arguments[1]}");
                                }
                                catch (Exception e)
                                {
                                    Console.WriteLine($"Faile on test {testNumber}: Incorrect/missed arguments/expected value \n " +
                                                    $"Message: {e.Message} \n" +
                                                    $"StackTrace: {e.StackTrace}\n" +
                                                    $"TargetSite: {e.TargetSite}");
                                    return;
                                }
                            }
                            if (childNode.Name == "expected")
                            {
                                try
                                {
                                    expectedValue = Convert.ToDouble(childNode.InnerText);
                                    Console.WriteLine($"{testNumber}| E: {expectedValue}");
                                }
                                catch (Exception e)
                                {
                                    Console.WriteLine($"Faile on test {testNumber}: Incorrect/missed arguments/expected value \n " +
                                                    $"Message: {e.Message} \n" +
                                                    $"StackTrace: {e.StackTrace}\n" +
                                                    $"TargetSite: {e.TargetSite}");
                                    return;
                                }
                            }
                        }
                        
                        var meth = type.GetMember(functionName).First() as MethodInfo;

                        object methodResult = 0;
                        try
                        {
                            methodResult = meth.Invoke(instance, new object[] { arguments[0], arguments[1] });
                        }
                        catch (Exception e)
                        {
                            Console.WriteLine($"Faile on test {testNumber}: Error in executing the function {functionName} \n " +
                                                    $"Message: {e.Message} \n" +
                                                    $"StackTrace: {e.StackTrace}\n" +
                                                    $"TargetSite: {e.TargetSite}");
                        }

                        if (expectedValue.CompareTo(Convert.ToDouble(methodResult)) == 0)
                        {
                            Console.WriteLine($"Success. \n Result: {methodResult}\n" +
                                                $"Expected: {expectedValue}");
                        }
                        else
                        {
                            Console.WriteLine($"Faile on test {testNumber}: Error in executing the function {functionName}\n" +
                                                $"Result: {methodResult}\n" +
                                                $"Expected: {expectedValue}");

                        }

                        testNumber++;
                    }                  
                }
            }
        }
    }
}
