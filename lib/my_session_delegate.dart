import 'package:atomic_sdk_flutter/atomic_stream_container.dart';
import 'package:flutter_boilerplate/atomic_configuration.dart';

class MySessionDelegate extends AACSessionDelegate {
  @override
  Future<String> authToken() {
    return Future.value(AtomicConfiguration.token);
  }
}
