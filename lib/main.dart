import 'package:atomic_sdk_flutter/atomic_session.dart';
import 'package:atomic_sdk_flutter/atomic_stream_container.dart';
import 'package:flutter/material.dart';
import 'package:flutter_boilerplate/atomic_configuration.dart';
import 'package:flutter_boilerplate/my_session_delegate.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

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
  const MyHomePage({Key? key, required this.title}) : super(key: key);
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  Future<bool> onLogin() async {
    AACSession.setApiBaseUrl(AtomicConfiguration.apiUrl);
    AACSession.initialise(
        AtomicConfiguration.environmentId, AtomicConfiguration.apiKey);
    return true;
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
      future: onLogin(),
      builder: (context, AsyncSnapshot<bool> snapshot) {

        if (! snapshot.hasData) {
          return CircularProgressIndicator();
        }

        return Scaffold(
          appBar: AppBar(
            title: Text(widget.title),
          ),
          body: Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                Container(
                    width: MediaQuery.of(context).size.width,
                    height: MediaQuery.of(context).size.height - 200,
                    child: AACStreamContainer(
                      configuration: AtomicConfiguration.configuration,
                      containerId: AtomicConfiguration.containerId,
                      sessionDelegate: MySessionDelegate(),
                    )),
              ],
            ),
          ),
        );
      },
    );
  }
}
