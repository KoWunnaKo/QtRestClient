#ifndef QTRESTCLIENTAUTH_AUTHREQUESTBUILDER_H
#define QTRESTCLIENTAUTH_AUTHREQUESTBUILDER_H

#include "QtRestClientAuth/qtrestclientauth_global.h"

#include <QtCore/QScopedPointer>
#include <QtCore/QLoggingCategory>

#include <QtNetworkAuth/qabstractoauth.h>

#include <QtRestClient/requestbuilder.h>

namespace QtRestClient::Auth {

class AuthExtenderPrivate;
//! An extender that adds OAuth information to a request
class Q_RESTCLIENTAUTH_EXPORT AuthExtender : public RequestBuilder::IExtender
{
public:
	//! Constructs the extender from an abstract OAuth interface
	AuthExtender(QAbstractOAuth *oAuth);
	~AuthExtender() override;

	bool requiresBody() const override;
	void extendRequest(QNetworkRequest &request, QByteArray &verb, QByteArray *body) const override;

private:
	QScopedPointer<AuthExtenderPrivate> d;
};

//! An extension of the RequestBuilder that uses a QAbstractOAuth to create authenticated requests
class Q_RESTCLIENTAUTH_EXPORT AuthRequestBuilder : public RequestBuilder
{
public:
	//! Constructs a builder with the given base url and an OAuth instance to authenticate requests with
	AuthRequestBuilder(const QUrl &baseUrl, QAbstractOAuth *oAuth = nullptr, QNetworkAccessManager *nam = nullptr);
	//! Copy constructor
	AuthRequestBuilder(const AuthRequestBuilder &other);
	//! Move constructor
	AuthRequestBuilder(AuthRequestBuilder &&other) noexcept;
	//! Copy assignment operator
	AuthRequestBuilder &operator=(const AuthRequestBuilder &other);
	//! Move assignment operator
	AuthRequestBuilder &operator=(AuthRequestBuilder &&other) noexcept;
	~AuthRequestBuilder();

	//! Sets the OAuth instance to authenticate requests created via build() or send()
	AuthRequestBuilder &setOAuth(QAbstractOAuth *oAuth, bool replaceNam = true);

private:
	friend class AuthRestClient;
	AuthRequestBuilder(RequestBuilder &&extendedBase);
};

Q_DECLARE_LOGGING_CATEGORY(logAuthExtender)

}

#endif // QTRESTCLIENTAUTH_AUTHREQUESTBUILDER_H
