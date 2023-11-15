import 'package:atomic_sdk_flutter/atomic_session.dart';
import 'package:atomic_sdk_flutter/atomic_stream_container.dart';
import 'package:flutter/material.dart';
import 'package:flutter_boilerplate/atomic_configuration.dart';
import 'package:flutter_boilerplate/my_session_delegate.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Atomic Boilerplate',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Atomic Boilerplate'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({required this.title, super.key});
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  bool _loggedIn = false;

  Future<bool> onLogin() async {
    await AACSession.setApiBaseUrl(AtomicConfiguration.apiUrl);
    await AACSession.initialise(
      AtomicConfiguration.environmentId,
      AtomicConfiguration.apiKey,
    );
    await AACSession.setSessionDelegate(MySessionDelegate());
    //await Future.delayed(Duration(seconds: 5)); // for testing loading.
    return true;
  }

  @override
  void initState() {
    onLogin().then((value) {
      setState(() {
        _loggedIn = value;
      });
    });
    // Atomic SDK redirects errors/exceptions to the FlutterError.onError pipeline
    FlutterError.onError = print;
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    final screenSize = MediaQuery.of(context).size;

    if (!_loggedIn) {
      return const CircularProgressIndicator();
    }
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: SafeArea(
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              SizedBox(
                width: screenSize.width,
                height: screenSize.height * 0.8,
                child: AACStreamContainer(
                  configuration: AtomicConfiguration.configuration,
                  containerId: AtomicConfiguration.containerId,
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
