# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rosapi_msgs:srv/GetParam.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetParam_Request(type):
    """Metaclass of message 'GetParam_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rosapi_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rosapi_msgs.srv.GetParam_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_param__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_param__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_param__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_param__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_param__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetParam_Request(metaclass=Metaclass_GetParam_Request):
    """Message class 'GetParam_Request'."""

    __slots__ = [
        '_name',
        '_default_value',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'default_value': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.default_value = kwargs.get('default_value', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.name != other.name:
            return False
        if self.default_value != other.default_value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @property
    def default_value(self):
        """Message field 'default_value'."""
        return self._default_value

    @default_value.setter
    def default_value(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'default_value' field must be of type 'str'"
        self._default_value = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GetParam_Response(type):
    """Metaclass of message 'GetParam_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rosapi_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rosapi_msgs.srv.GetParam_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_param__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_param__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_param__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_param__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_param__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetParam_Response(metaclass=Metaclass_GetParam_Response):
    """Message class 'GetParam_Response'."""

    __slots__ = [
        '_value',
    ]

    _fields_and_field_types = {
        'value': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.value = kwargs.get('value', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.value != other.value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def value(self):
        """Message field 'value'."""
        return self._value

    @value.setter
    def value(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'value' field must be of type 'str'"
        self._value = value


class Metaclass_GetParam(type):
    """Metaclass of service 'GetParam'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rosapi_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rosapi_msgs.srv.GetParam')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_param

            from rosapi_msgs.srv import _get_param
            if _get_param.Metaclass_GetParam_Request._TYPE_SUPPORT is None:
                _get_param.Metaclass_GetParam_Request.__import_type_support__()
            if _get_param.Metaclass_GetParam_Response._TYPE_SUPPORT is None:
                _get_param.Metaclass_GetParam_Response.__import_type_support__()


class GetParam(metaclass=Metaclass_GetParam):
    from rosapi_msgs.srv._get_param import GetParam_Request as Request
    from rosapi_msgs.srv._get_param import GetParam_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
