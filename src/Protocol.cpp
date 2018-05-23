#include "ProtocolImpl.h"

COMMSDSL_EXP_TEMPLATE template class COMMSDSL_API std::unique_ptr<commsdsl::ProtocolImpl>;

#include "commsdsl/Protocol.h"

namespace commsdsl
{

Protocol::Protocol()
  : m_pImpl(new ProtocolImpl)
{
}

void Protocol::setErrorReportCallback(Protocol::ErrorReportFunction&& cb)
{
    m_pImpl->setErrorReportCallback(std::move(cb));
}

Protocol::~Protocol() = default;

bool Protocol::parse(const std::string& input)
{
    return m_pImpl->parse(input);
}

bool Protocol::validate()
{
    return m_pImpl->validate();
}

Schema Protocol::schema() const
{
    return m_pImpl->schema();
}

Protocol::NamespacesList Protocol::namespaces() const
{
    return m_pImpl->namespacesList();
}

Field Protocol::findField(const std::string& externalRef) const
{
    return Field(m_pImpl->findField(externalRef));
}

Protocol::MessagesList Protocol::allMessages() const
{
    return m_pImpl->allMessages();
}

void Protocol::addExpectedExtraPrefix(const std::string& value)
{
    return m_pImpl->addExpectedExtraPrefix(value);
}

const Protocol::PlatformsList&Protocol::platforms() const
{
    return m_pImpl->platforms();
}

} // namespace commsdsl
